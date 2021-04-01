#include "buffergrayscale.ih"

void BufferGrayscale::flush()
{
    std::memset(d_pixelArray, 0, d_size);
}
