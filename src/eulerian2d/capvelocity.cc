#include "eulerian2d.ih"

// Make sure particle velocity does not exceed maximum velocity parameter.

void FluidState::capVelocity(FluidParticle *p)
{
    float speed = sqrt((p->vel * p->vel).sum());
    if (speed > vmax)
        p->vel *= vmax / speed;

}
