#include "sph2d.ih"

// Compute density at a particle as the weighted sum of the masses of its
// neighbouring particles using the kernel function W.

void FluidState::computeDensity(FluidParticle *p,
                                 size_t n,
                                 FluidParticle **neighbours)
{
    float sum = 0;
    for (size_t idx = 0; idx != n; ++idx)
        sum += W(p, neighbours[idx]);
    p->dens = mass * sum;
}
