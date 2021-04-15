#include "buffergrayscale.ih"

void BufferGrayscale::clear()
{
    std::memset(d_pixelArray, 0, d_size);
}
