#include "sph2d.ih"

// Make sure that the particle position is within bounds.

void FluidState::checkBoundary(FluidParticle *p)
{
    // Recall that coordinate zero (i.e., pos[0]) is the vertical direction

    // top boundary
    if (p->pos[0] - h < 0)
        p->pos[0] = 0 + h;

    // left boundary
    if (p->pos[1] - h < 0)
        p->pos[1] = 0 + h;

    // bottom boundary
    if (p->pos[0] + h > buf->height() - 1)
        p->pos[0] = buf->height() - 1 - h;

    // right boundary
    if (p->pos[1] + h > buf->width() - 1)
        p->pos[1] = buf->width() - 1 - h;

}
