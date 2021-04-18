#include "eulerian2d.ih"

// Gradient of kernel function.

std::valarray<float> FluidState::gradW(FluidParticle *p1,
                                       FluidParticle *p2) const
{
    float d = distance(p1,p2);
    float q = d/h;
    std::valarray<float> u = {0,0};
    if (q >= 2 || q == 0)
        return u;
    else {
        float s = -3 * pow(2-q,2);
        u = p1->pos - p2->pos;
        if (q >= 1)
            return s * alpha / (d * h) * u;
        else
            return (s + 12 * pow(1-q,2)) * alpha / (d * h) * u;
    }
}
