#include "eulerian2d.ih"

FluidState::FluidState(BufferGrayscale *buf,
                       size_t numParticles,
                       float restDensity,
                       float viscosity,
                       float particleSpacing,
                       float pressureStiffness)
    :
    numParticles(numParticles),
    h(particleSpacing),
    dens(restDensity),
    visc(viscosity),
    dt(0.1),
    vmax(0.5 * h / dt),
    alpha(5 / (14 * M_PI * h*h)),
    mass(pow(h,3) * dens),
    k(pressureStiffness),
    particles(new FluidParticle *[numParticles]),
    buf(buf)
{
    for (size_t idx = 0; idx != numParticles; ++idx)
    {
        particles[idx] = new FluidParticle;
        particles[idx]->pos = {static_cast<float>(rand()%200 + 100),
                               static_cast<float>(rand()%200 + 100)};
        particles[idx]->vel = {0,0};
        particles[idx]->dens = 1;
        particles[idx]->pres = 1;
    }
}
