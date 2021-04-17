#include "eulerian2d.ih"

// acceleration on particle due to pressure from neighbouring particles

std::valarray<float> FluidState::accPres(FluidParticle *p,
                             size_t n,
                             FluidParticle **neighbours) const
{
    std::valarray<float> u{0,2};
    for (size_t idx = 0; idx != n; ++idx)
    {
        FluidParticle *pNeib = neighbours[idx];
        u += ((p->pres / pow(p->dens, 2)) + (pNeib->pres / pow(pNeib->dens, 2)))
             * gradW(p,pNeib);
    }
    return -mass * u;
}
