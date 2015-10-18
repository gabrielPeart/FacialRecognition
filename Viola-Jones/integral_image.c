#include "integral_image.h"
#include "load_image.h"

void integral_image(t_image *image)
{
  int x, y;

  init_integral_image(image);
  for (int i = 0; i < image->surface->w; ++i)
    image->integral[0][i] = i + 1;
  for (int i = 0; i < image->surface->h; ++i)
    image->integral[i][0] = i + 1;

  for (y = 1; y < image->surface->h; ++y)
    for (x = 1; x < image->surface->w; ++x)
      image->integral[y][x] = 1 + image->integral[y - 1][x]
                                + image->integral[y][x - 1]
                                - image->integral[y - 1][x - 1];
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
