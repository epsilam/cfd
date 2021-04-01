#include "buffergrayscale.ih"

std::ostream& operator <<(std::ostream &out, const BufferGrayscale &other)
{
    out << "P5"           << "\n"
        << other.width()  << " "
        << other.height() << "\n"
        << 255            << "\n"
       ;
    out.write(other.pixelArray(), other.height() * other.width());
    out.flush();
    return out;
}
