#include "eulerian2d.ih"

void FluidState::nextState()
{
    for (size_t idx = 0; idx != numParticles; ++idx)
    {
        FluidParticle *p = particles[idx];

        // find neighbours of p
        FluidParticle *neighbours[numParticles];
        size_t numNeibs = 0; // number of neighbours of p
        for (size_t jdx = 0; jdx != numParticles; ++jdx)
        {
            if (distance(p,particles[jdx]) < 2 * h)
                neighbours[numNeibs++] = particles[jdx];
        }

        // compute density and pressure of p
        computeDensity(p,numNeibs,neighbours);
        computePressure(p);

        // calculate accelerations on p
        std::valarray<float> gravity = {100,0}; // gravity in num units per second
                                               // squared (downward direction)
        std::valarray<float> aP = accPres(p,numNeibs,neighbours);
        std::valarray<float> aV = accVisc(p,numNeibs,neighbours);

        // compute normal forces for boundary
        if (p->pos[0] > 398)
        {
            gravity = {0,0};
        }

        // compute sum of accelerations
        std::valarray<float> acc = aP + aV + gravity;

        // update velocity of p based on acceleration
        p->vel += dt * acc;

        // make sure velocity does not exceed maximum speed
        capVelocity(p);

        if (p->vel[0] < -vmax)
            p->vel[0] = -vmax;
        if (p->vel[1] < -vmax)
            p->vel[1] = -vmax;
        if (p->vel[0] > vmax)
            p->vel[0] = vmax;
        if (p->vel[1] > vmax)
            p->vel[1] = vmax;

        //  update position based on velocity
        p->pos += dt * p->vel;

        // boundary checking.
        // particles must have x and y coords between 0 and 399

        // left boundary
        if (p->pos[0] < 0)
        {
            p->pos[0] = 0;
            p->vel[0] = std::max(p->vel[0],0.0f);
        }

        // top boundary
        if (p->pos[1] < 0)
        {
            p->pos[1] = 0;
            p->vel[1] = std::max(p->vel[1],0.0f);
        }

        // right boundary
        if (p->pos[0] > 399)
        {
            p->pos[0] = 399;
            p->vel[0] = std::min(p->vel[0],399.0f);
        }

        // bottom boundary
        if (p->pos[1] > 399)
        {
            p->pos[1] = 399;
            p->vel[1] = std::min(p->vel[1],399.0f);
        }

        // push position of particle to buffer
        buf->drawCircle(round(p->pos[0]),
                        round(p->pos[1]),
                        round(2 * h),
                        static_cast<char>(255));
    }
    buf->write();
    buf->clear();
}
