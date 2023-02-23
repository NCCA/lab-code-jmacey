#include "Image.h"

Image::Image(int _w, int _h) : m_width{_w},m_height{_h}
{
  m_pixels=std::make_unique<RGBA []>(_w*_h);
}

int Image::width() const
{
  return m_width;
}

int Image::height() const
{
  return m_height;
}

RGBA Image::getPixel(int _x, int _y) const
{
  int index=(m_width*_y) + _x;
  return m_pixels[index];
}

void Image::setPixel(int _x, int _y,unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
{

  int index=(m_width*_y) + _x;

  m_pixels[index].r=_r;
  m_pixels[index].g=_g;
  m_pixels[index].b=_b;
  m_pixels[index].a=_a;
  
}



