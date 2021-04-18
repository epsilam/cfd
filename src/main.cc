#include "main.ih"

int main()
{
   BufferGrayscale buf(400,400);
   FluidState fluid(&buf,
                    500, // num particles
                    20,  // density
                    0.1, // viscosity
                    7,  // spacing
                    0.3  // pressure stiffness
   );
   for (size_t idx = 0; idx != 300; ++idx)
   {
      fluid.nextState();
   }
}
