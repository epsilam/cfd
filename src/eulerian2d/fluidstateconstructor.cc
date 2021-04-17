#include "eulerian2d.ih"

FluidState::FluidState(size_t numParticles,
                       float restDensity,
                       float viscosity,
                       float particleSpacing,
                       float pressureStiffness)
    :
    numParticles(numParticles),
    h(particleSpacing),
    dens(restDensity),
    visc(viscosity),
    vmax(10 * h),
    dt(0.1 * h / vmax),
    alpha(5 / (14 * M_PI * h*h)),
    mass(pow(h,3) * dens),
    k(pressureStiffness),
    particles(new FluidParticle *[numParticles])
{

}
