#include "sph2d.ih"

void FluidState::computePressure(FluidParticle *p)
{
    p->pres = k * (pow(p->dens / dens, 7) - 1);
}
