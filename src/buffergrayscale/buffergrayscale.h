#ifndef BUFFERGRAYSCALE_H
#define BUFFERGRAYSCALE_H

#include <iostream>

class BufferGrayscale // Buffer containing pixels of 1 byte each, representing
                      // some char value between 0 and 255, 0 being black.
{
    size_t d_height;
    size_t d_width;
    size_t d_size;
    char *d_pixelArray; // Pixel array of size d_height * d_width.

    public:
        BufferGrayscale(size_t height, size_t width);
        ~BufferGrayscale();
        size_t height() const;
        size_t width() const;

        void set(size_t i, size_t j, char value);
        char get(size_t i, size_t j) const;

        void flush();
                                 // Write buffer to an output stream.
        friend std::ostream& operator <<(std::ostream &out,
                                         const BufferGrayscale &other);

    private:
        char *pixelArray() const;
};

inline size_t BufferGrayscale::height() const
{
    return d_height;
}

inline size_t BufferGrayscale::width() const
{
    return d_width;
}

inline char *BufferGrayscale::pixelArray() const
{
    return d_pixelArray;
}



#endif