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
        std::valarray<float> gravity = {0,10}; // gravity is 10 units per second
                                               // squared (downward direction)
        std::valarray<float> acc{0,2};
        acc =   accPres(p,numNeibs,neighbours)
            + accVisc(p,numNeibs,neighbours)
            + gravity;

        // change velocity and position of p based on acceleration
        p->vel += dt * acc;
        p->pos += dt * p->vel;

        // boundary checking.
        // particles must have x and y coords between 0 and 400

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
        if (p->pos[0] > 400)
        {
            p->pos[0] = 400;
            p->vel[0] = std::min(p->vel[0],400.0f);
        }

        // bottom boundary
        if (p->pos[1] > 400)
        {
            p->pos[1] = 400;
            p->vel[1] = std::min(p->vel[1],400.0f);
        }

        // make sure velocity does not exceed maximum speed
        if (p->vel[0] < -vmax)
            p->vel[0] = -vmax;
        if (p->vel[1] < -vmax)
            p->vel[1] = -vmax;
        if (p->vel[0] > vmax)
            p->vel[0] = vmax;
        if (p->vel[1] > vmax)
            p->vel[1] = vmax;

    }
}
