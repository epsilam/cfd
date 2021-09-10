#include "sph2d.ih"

// Acceleration on particle due to viscous interactions
// with neighbouring particles.

std::valarray<float> FluidState::accVisc(FluidParticle *p,
                                         size_t n,
                                         FluidParticle **neighbours) const
{
    std::valarray<float> u = {0,0};
    for (size_t idx = 0; idx != n; ++idx)
    {
        FluidParticle *pNeib = neighbours[idx];
        std::valarray<float> x = p->pos - pNeib->pos;
        std::valarray<float> gw = gradW(p,pNeib);
        u += (p->vel - pNeib->vel)
            * (x * gw).sum()
            / (pNeib->dens * ((x * x).sum() + 0.01 * pow(h, 2)));
    }
    return 2 * visc * mass * u;
}
