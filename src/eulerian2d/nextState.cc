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
        std::valarray<float> aPres = accPres(p,numNeibs,neighbours);
        std::valarray<float> aVisc = accVisc(p,numNeibs,neighbours);
        std::valarray<float> aBoun = accBoun(p);
        std::valarray<float> aGrav = {100,0};

        // compute sum of accelerations
        std::valarray<float> acc = aPres + aVisc + aBoun + aGrav;

        // update velocity of p based on acceleration
        p->vel += dt * acc;
        capVelocity(p);

        //  update position based on velocity
        p->pos += dt * p->vel;
        checkBoundary(p);

        // push position of particle to buffer
        buf->drawCircle(round(p->pos[0]),
                        round(p->pos[1]),
                        round(h),
                        static_cast<char>(255));
    }
    buf->write();
    buf->clear();
}
