#include "sph2d.ih"

FluidState::~FluidState()
{
    for (size_t idx = 0; idx != numParticles; ++idx)
        delete particles[idx];
    delete[] particles;
    delete buf;
}
