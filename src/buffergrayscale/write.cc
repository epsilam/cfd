#include "buffergrayscale.ih"

void BufferGrayscale::write()
{
    std::cout << "P5"    << "\n"
        << d_width  << " "
        << d_height << "\n"
        << 255      << "\n"
        ;
    std::cout.write(d_pixelArray, d_size);
    std::cout.flush();
}
