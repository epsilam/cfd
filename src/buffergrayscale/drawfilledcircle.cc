#include "buffergrayscale.ih"

void BufferGrayscale::drawFilledCircle(size_t i,
                                       size_t j,
                                       size_t radius,
                                       char value)
{
    int r = static_cast<int>(radius);
    for (int x = -r; x <= r; x++)
        for (int y = -r; y <= +r; y++)
            if (x*x + y*y <= r*r)
                safeSet(i+x, j+y, value);
}
