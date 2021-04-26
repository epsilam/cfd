#include "main.ih"

int main()
{
   FluidState fluid(400,  // frame height
                    400,  // frame width
                    1,    // frame skip (see eulerian2d.h)
                    300,  // num particles
                    10,   // density
                    0.5,  // viscosity
                    7,    // spacing
                    1.0   // pressure stiffness
   );

   for (size_t idx = 0; idx != 500; ++idx)
   {
      fluid.nextState();
   }
}
