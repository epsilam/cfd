#include "imglib.ih"

class Buffer
{
    size_t d_height;
    size_t d_width;
    char *d_pix;

    public:
        Buffer(size_t height, size_t width);
        ~Buffer();
        size_t height();
        size_t width();

        void set(size_t i, size_t j, char value);
        char get(size_t i, size_t j);

        void write();
};

Buffer::Buffer(size_t height, size_t width)
:
    d_height(height),
    d_width(width),
    d_pix(new char[height * width]())
{
}

Buffer::~Buffer()
{
    delete[] d_pix;
}

inline size_t
Buffer::height()
{
    return d_height;

}

inline size_t
Buffer::width()
{
    return d_width;
}

void
Buffer::set(size_t i, size_t j, char value)
{
    if (i >= d_height || j >= d_width)
    {
        throw std::out_of_range ("Buffer index out of range");
    } else
    {
        d_pix[i * d_width + j] = value;
    }
}

char
Buffer::get(size_t i, size_t j)
{
    if (i >= d_height || j >= d_width)
    {
        throw std::out_of_range ("Buffer index out of range");
    } else
    {
        return d_pix[i * d_width + j];
    }
}

void
Buffer::write()
{

}
