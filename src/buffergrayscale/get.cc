#include "buffergrayscale.ih"

char BufferGrayscale::get(size_t i, size_t j) const
{
    if (i >= d_height || j >= d_width)
    {
        throw std::out_of_range ("BufferGrayscale index out of range");
    } else
    {
        return d_pixelArray[i * d_width + j];
    }
}
