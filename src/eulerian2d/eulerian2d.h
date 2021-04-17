#ifndef BUFFERGRAYSCALE_H
#define BUFFERGRAYSCALE_H

#include <valarray>

// current deal dimensions: 400x400 grid
// h = 5
// numParticles = 30

class FluidState
{
    struct FluidParticle
    {
        std::valarray<float> pos;
        std::valarray<float> vel;
        float dens; // density
        float pres; // pressure
    };

    FluidParticle **particles;
    size_t numParticles; // number of particles
    float h;             // particle spacing
    float dens;          // rest density (constant)
    float visc;          // viscosity
    float vmax;          // maximum velocity
    float dt;            // time step det'd by Courant-Freidrichs-Lewy condition
    float alpha;         // scaling factor for kernel function
    float mass;          // mass of each particle
    float k;             // stiffness factor in pressure state equation

    public:
        FluidState(size_t numParticles,
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
        std::valarray<float> accGrav(FluidParticle *p,
                                     size_t n,
                                     FluidParticle **neighbours) const;


};

#endif
