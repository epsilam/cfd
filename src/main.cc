#include "main.ih"

int main()
{
   //BufferGrayscale buf(400,400);
   FluidState fluid(400,  // frame height
                    400,  // frame width
                    300, // num particles
                    3,    // density
                    0.5,  // viscosity
                    8,    // spacing
                    1.0   // pressure stiffness
   );

   for (size_t idx = 0; idx != 300; ++idx)
   {
      fluid.nextState();
   }
}
