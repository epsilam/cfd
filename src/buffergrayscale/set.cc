#include "buffergrayscale.ih"

void BufferGrayscale::set(size_t i, size_t j, char value)
{
    if (i >= d_height || j >= d_width)
    {
        throw std::out_of_range ("BufferGrayscale index out of range");
    } else
    {
        d_pixelArray[i * d_width + j] = value;
    }
}
