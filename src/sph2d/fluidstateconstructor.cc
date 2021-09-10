#include "eulerian2d.ih"

FluidState::FluidState(size_t frameHeight,
                       size_t frameWidth,
                       size_t frameSkip,
                       size_t numParticles,
                       float restDensity,
                       float viscosity,
                       float particleSpacing,
                       float pressureStiffness)
    :
    frameNum(0),
    frameSkip(frameSkip),
    numParticles(numParticles),
    h(particleSpacing),
    dens(restDensity),
    visc(viscosity),
    dt(0.1),
    vmax(0.6 * h / dt),
    alpha(5 / (14 * M_PI * h*h)), // Note: this alpha is for 2d simulations
    mass(pow(h,3) * dens),
    k(pressureStiffness),
    particles(new FluidParticle *[numParticles]),
    buf(new BufferGrayscale(frameHeight, frameWidth))
{
    // Create initial particles with randomized position.
    for (size_t idx = 0; idx != numParticles; ++idx)
    {
        particles[idx] = new FluidParticle;
        particles[idx]->pos = {static_cast<float>(rand()%100 + 100),
                               static_cast<float>(rand()%100 + 0)};
        particles[idx]->vel = {0,50};
        particles[idx]->dens = 1;
        particles[idx]->pres = 1;
    }
}
