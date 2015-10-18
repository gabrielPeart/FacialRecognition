#include <stdlib.h>
#include <stdio.h>
#include "pixel_operations.h"
#include "integral_image.h"

int *getIntegralImage(SDL_Surface *image, int *integral, size_t l, size_t c)
{
  for(size_t i = 0; i < l; i++)
  {
    for(size_t j = 0; j < c; j++)
    {
      integral[i * c + j] = 0;
      someIntegral(integral, i, j, c);
      integral[i * c + j] += (int)getpixel(image, (unsigned)j, (unsigned)i);
      if(j > 0 && i > 0)
        integral[i * c + j] -= integral[(i - 1) * c + (j - 1)];
    }
  }
  return integral;
}
void someIntegral(int *integral, size_t l, size_t c, size_t lenght)
{
  for(size_t i = 0; i < l; i++)
    integral[l * lenght + c] += integral[i * lenght + c];
  for(size_t j = 0; j < c; j++)
    integral[l * lenght + c] += integral[l * lenght + j];
  return;
}
