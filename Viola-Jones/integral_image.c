#include "integral_image.h"
#include "load_image.h"
#include "pixel_operations.h"

void integral_image(t_image *image)
{
  unsigned x, y;

  init_integral_image(image);
  image->integral[0][0] = getpixel(image->surface, 0, 0);
  for (unsigned i = 1; i < (unsigned)image->surface->w; ++i)
    image->integral[0][i] = image->integral[0][i-1] + getpixel(image->surface, i, 0);
  for (unsigned i = 1; i < (unsigned)image->surface->h; ++i)
    image->integral[i][0] = image->integral[i-1][0] + getpixel(image->surface, 0, i);

  for (y = 1; y < (unsigned)image->surface->h; ++y)
    for (x = 1; x < (unsigned)image->surface->w; ++x)
      image->integral[y][x] = getpixel(image->surface, x, y) + image->integral[y - 1][x] + image->integral[y][x - 1] - image->integral[y - 1][x - 1];
}

void init_integral_image(t_image *image)
{
  image->integral = malloc(image->surface->h * sizeof(int *));
  for (int i = 0; i < image->surface->h; ++i)
    image->integral[i] = malloc(image->surface->w * sizeof(int));
}


unsigned long pixels_sum(t_image *image, int x, int y, int width, int height)
{
  return image->integral[y][x] + image->integral[y + height - 1][x + width - 1] - image->integral[y][x + width - 1] - image->integral[y + height - 1][x];
}
