#include "buffergrayscale.ih"

BufferGrayscale::BufferGrayscale(size_t height, size_t width)
:
    d_height(height),
    d_width(width),
    d_size(height*width),
    d_pixelArray(new char[height * width]())
{}
