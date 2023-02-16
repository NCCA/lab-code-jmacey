#include <gtest/gtest.h>
#include "Image.h"


TEST(Image,ctor)
{
  auto img=Image();
  ASSERT_EQ(img.width(),0);
  ASSERT_EQ(img.height(),0);
  
}