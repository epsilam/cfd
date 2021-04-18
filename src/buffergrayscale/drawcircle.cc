#include "buffergrayscale.ih"

void BufferGrayscale::drawCircle(size_t i, size_t j, size_t radius, char value)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;
    safeSet(i+x, j+y, value);
    safeSet(i-x, j+y, value);
    safeSet(i+x, j-y, value);
    safeSet(i-x, j-y, value);
    safeSet(i+y, j+x, value);
    safeSet(i-y, j+x, value);
    safeSet(i+y, j-x, value);
    safeSet(i-y, j-x, value);

    while (y >= x) {
        x++;
        if (d > 0)
        {
            y--;
            d += 4 * (x - y) + 10;
        }
        else
            d += 4 * x + 6;
        safeSet(i+x, j+y, value);
        safeSet(i-x, j+y, value);
        safeSet(i+x, j-y, value);
        safeSet(i-x, j-y, value);
        safeSet(i+y, j+x, value);
        safeSet(i-y, j+x, value);
        safeSet(i+y, j-x, value);
        safeSet(i-y, j-x, value);
    }
}
