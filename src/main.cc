#include "main.ih"

int main()
{
   //BufferGrayscale buf(100,100);

   //for (size_t i = 0; i != 100; ++i)
   //{
   //   buf.set(i,i,255);
   //   buf.write();
   //   buf.clear();
   //   std::cerr << "image written";
   //}

   BufferGrayscale buf(400,400);
   FluidState fluid(&buf,
                    200, // num particles
                    20, //dens
                    1.0, // viscosity
                    10, // spacing
                    0.2 // pressure stiffness
   );
   for (size_t idx = 0; idx != 300; ++idx)
   {
      fluid.nextState();
   }

}
