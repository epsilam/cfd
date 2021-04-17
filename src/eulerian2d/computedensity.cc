#include "eulerian2d.ih"

void FluidState::computeDensity(FluidParticle *p,
                                 size_t n,
                                 FluidParticle **neighbours)
{
    float sum = 0;
    for (size_t idx = 0; idx != n; ++idx)
        sum += W(p, neighbours[idx]);
    p->dens = mass * sum;
}
