#include "buffergrayscale.ih"

void BufferGrayscale::drawBlurredCircle(size_t i,
                                       size_t j,
                                       size_t radius)
{
    int r = static_cast<int>(radius);
    for (int x = -r; x <= r; x++)
        for (int y = -r; y <= +r; y++)
        {
            float d = sqrt(x*x + y*y);
            if (d <= r)
                safeSet(i+x,
                        j+y,
                        static_cast<char>(round(255 * (1 - d / radius))));
        }
}
