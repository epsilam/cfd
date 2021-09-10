#include "eulerian2d.ih"

// Acceleration on particle due to boundary.

std::valarray<float> FluidState::accBoun(FluidParticle *p) const
{
    std::valarray<float> out = {0,0};

    float minBounDist = 1; // The distance a particle must be from the boundary
                           // for the boundary normal force to apply.

    float coeffRes = 0.8; // Coefficient of restitution (between 0 and 1).
                          // Controls how much of the particle's momentum is
                          // absorbed when colliding with the wall.

    // top boundary
    if (p->pos[0] - h < 0 + minBounDist)
        out[0] = - 2 * p->vel[0] / dt * coeffRes;

    // left boundary
    if (p->pos[1] - h < 0 + minBounDist)
        out[1] = - 2 * p->vel[1] / dt * coeffRes;

    // bottom boundary
    if (p->pos[0] + h > buf->height() - 1 - minBounDist)
        out[0] = - 2 * p->vel[0] / dt * coeffRes;

    // right boundary
    if (p->pos[1] + h > buf->width() - 1 - minBounDist)
        out[1] = - 2 * p->vel[1] / dt * coeffRes;

    return out;
}
