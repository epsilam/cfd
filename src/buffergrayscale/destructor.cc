#include "buffergrayscale.ih"

BufferGrayscale::~BufferGrayscale()
{
    delete[] d_pixelArray;
}
