#ifndef BUFFERGRAYSCALE_H
#define BUFFERGRAYSCALE_H

struct FluidParticle
{
    float xpos;
    float ypos;
    float xvel;
    float yvel;
    float dens; // density
    float pres; // pressure
};

class FluidState
{
    FluidParticle *particles;
    float dens;                 // rest density (constant)
    float visc;                   // viscosity
    float vmax;                 // maximum velocity
    float dt;                   // time step
    float alpha;                // scaling factor for kernel function

    public:
        FluidState(int numParticles,
                   float restDensity,
                   float viscosity,
                   float particleSpacing);
        ~FluidState();

        void nextState();

    private:
        float distance(FluidParticle *pi, FluidParticle *pj) const;
        float W(FluidParticle *pi, FluidParticle *pj) const;
        float gradW(FluidParticle *pi, FluidParticle *pj) const;


};

#endif
