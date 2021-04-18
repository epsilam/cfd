#include "main.ih"

int main()
{
   BufferGrayscale buf(400,400);
   FluidState fluid(&buf,
                    200, // num particles
                    20,  // density
                    1.0, // viscosity
                    10,  // spacing
                    1.0  // pressure stiffness
   );
   for (size_t idx = 0; idx != 300; ++idx)
   {
      fluid.nextState();
   }
}
