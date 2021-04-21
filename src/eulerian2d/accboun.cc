#include "eulerian2d.ih"

// Acceleration on particle due to boundary.

std::valarray<float> FluidState::accBoun(FluidParticle *p) const
{
    std::valarray<float> out = {0,0};

    float minBounDist = 1; // The distance a particle must be from the boundary
                           // for the boundary normal force to apply.

    float bounRes = 1; // Acceleration due to small resistive force that pushes
                       // particles away from the boundary.

    // top boundary
    if (p->pos[0] - h < 0 + minBounDist)
        out[0] = - 2 * p->vel[0] / dt + bounRes;

    // left boundary
    if (p->pos[1] - h < 0 + minBounDist)
        out[1] = - 2 * p->vel[1] / dt + bounRes;

    // bottom boundary
    if (p->pos[0] + h > buf->height() - 1 - minBounDist)
        out[0] = - 2 * p->vel[0] / dt - bounRes;

    // right boundary
    if (p->pos[1] + h > buf->width() - 1 - minBounDist)
        out[1] = - 2 * p->vel[1] / dt - bounRes;

    return out;
}
