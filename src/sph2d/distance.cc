#include "sph2d.ih"

float FluidState::distance(FluidParticle *p1, FluidParticle *p2) const
{
    std::valarray<float> d = p1->pos - p2->pos;
    return sqrt((d * d).sum());
}
