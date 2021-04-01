#include "main.ih"

int main()
{
   BufferGrayscale buf(100,100);

   for (size_t i = 0; i != 100; ++i)
   {
      buf.set(i,i,255);
      std::cout << buf;
      buf.flush();
   }
}
