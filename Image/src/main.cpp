#include <iostream>
#include <cstdlib>
#include <random>
#include "Image.h"

int main()
{
  auto img=Image(512,512);

  img.clear(255,0,0,255);
  img.save("red.jpg");
  img.clear(0,255,0,255);
  img.save("green.jpg");
  img.clear(0,0,255,255);
  img.save("blue.jpg");
  
  Image n(100,100,255,0,255);
  n.save("new.tiff");

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> randWidth(-10,img.width()-1);
  std::uniform_int_distribution<> randHeight(-10,img.height()-1);
  std::uniform_int_distribution<> colour(0,255);
  std::uniform_real_distribution<float> zeroToOne(0.0f,1.0f);

  
  std::cout<<"Image Demo\n";
  for(int i=0; i<1000; i++)
  {
    auto r=colour(gen);
    auto g=colour(gen);
    auto b=colour(gen);
    auto x=randWidth(gen);
    auto y=randHeight(gen);
  for (size_t s=0; s<250+randWidth(gen); ++s)
    {
      auto splat_size= 10;
      auto alpha = 2 * M_PI * zeroToOne(gen);
      auto radius = splat_size * sqrtf(zeroToOne(gen));
      auto rx = x + int(radius * cosf(alpha)); 
      auto ry = y + int(radius * sinf(alpha)); 
      img.setPixel(rx,ry,r,g,b);
    }

  
  }


  img.save("test.jpg");

  return EXIT_SUCCESS;
}