#include "eulerian2d.ih"

// kernel function with compact support

float FluidState::W(FluidParticle *p1, FluidParticle *p2) const
{
   float q = distance(p1,p2)/h;
   if (q >= 2)
       return 0;
   else {
       float s = pow(2-q,3);
       if (q >= 1 && q < 2)
           return  alpha * s;
       else // q must now satisfy 0 <= q < 1 here.
           return alpha * (s - 4 * pow(1-q,3));
   }
}
