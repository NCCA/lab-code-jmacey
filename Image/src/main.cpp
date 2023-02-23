#include <iostream>
#include <cstdlib>
#include <random>
#include "Image.h"

int main()
{
  auto img=Image(512,512);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> randWidth(0,img.width()-1);
  std::uniform_int_distribution<> randHeight(0,img.height()-1);
  std::uniform_int_distribution<> colour(0,255);
  
  std::cout<<"Image Demo\n";
  for(int i=0; i<500000; i++)
  {
    auto r=colour(gen);
    auto g=colour(gen);
    auto b=colour(gen);
    auto x=randWidth(gen);
    auto y=randHeight(gen);
    img.setPixel(x,y,r,g,b);
  
  }


  img.save("test.jpg");

  return EXIT_SUCCESS;
}