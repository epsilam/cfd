#ifndef EULERIAN2D_H
#define EULERIAN2D_H

#include <valarray>
#include "../buffergrayscale/buffergrayscale.h"

class FluidState
{
    struct FluidParticle
    {
        std::valarray<float> pos;
        std::valarray<float> vel;
        float dens; // density
        float pres; // pressure
    };

    size_t frameNum;           // current frame number, incremented in nextState()

    size_t const frameSkip;    // If n is the frameSkip, then only every n'th
                               // frame is written to the image buffer, but
                               // particle accelerations, velocities, positions
                               // are still computed.
                               // A frameSkip of 1 means every frame is written.

    size_t const numParticles; // number of particles
    float const h;             // particle spacing
    float const dens;          // rest density (constant)
    float const visc;          // viscosity
    float const dt;            // time step det'd by Courant-Freidrichs-Lewy condition
    float const vmax;          // maximum velocity
    float const alpha;         // scaling factor for kernel function
    float const mass;          // mass of each particle
    float const k;             // stiffness factor in pressure state equation
    FluidParticle **particles;
    BufferGrayscale *buf;

    public:
        FluidState(size_t frameHeight,
                   size_t frameWidth,
                   size_t frameSkip,
                   size_t numParticles,
                   float restDensity,
                   float viscosity,
                   float particleSpacing,
                   float pressureStiffness);
        ~FluidState();

        void nextState(); // finding neighbours is done in this function

    private:
        float distance(FluidParticle *p1, FluidParticle *p2) const;

        float W(FluidParticle *p1, FluidParticle *p2) const;
        std::valarray<float> gradW(FluidParticle *p1, FluidParticle *p2) const;

        void computeDensity(FluidParticle *p,
                             size_t n,              // number of neighbours
                             FluidParticle **neighbours);
        void computePressure(FluidParticle *p);

        std::valarray<float> accPres(FluidParticle *p,
                                     size_t n,
                                     FluidParticle **neighbours) const;
        std::valarray<float> accVisc(FluidParticle *p,
                                     size_t n,
                                     FluidParticle **neighbours) const;
        std::valarray<float> accBoun(FluidParticle *p) const;

        void checkBoundary(FluidParticle *p);
        void capVelocity(FluidParticle *p);


};

#endif
