#include "buffergrayscale.ih"

// set pixel without throwing out of range exception

void BufferGrayscale::safeSet(size_t i, size_t j, char value)
{
    if (i < d_height && j < d_width)
        d_pixelArray[i * d_width + j] = value;
}
