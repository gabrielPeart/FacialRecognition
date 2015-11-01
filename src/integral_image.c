#include "integral_image.h"
#include "load_image.h"
#include "pixel_operations.h"
#include <err.h>

void integral_image(t_image *image)
{
  int x, y;

  init_integral_image(image);
  image->integral[0][0] = getgrey(image->bw, 0, 0);

  for (int i = 1; i < image->bw->w; ++i)
    image->integral[0][i] = image->integral[0][i-1] + getgrey(image->bw, i, 0);

  for (int i = 1; i < image->bw->h; ++i)
    image->integral[i][0] = image->integral[i-1][0] + getgrey(image->bw, 0, i);

  for (y = 1; y < image->bw->h; ++y)
    for (x = 1; x < image->bw->w; ++x)
      image->integral[y][x] = getgrey(image->bw, x, y)+ image->integral[y - 1][x] + image->integral[y][x - 1] - image->integral[y - 1][x - 1];
}

void init_integral_image(t_image *image)
{
  warn("h: %d; w: %d", image->bw->h, image->bw->w);
  image->integral = malloc(image->bw->h * sizeof(int *));
  for (int i = 0; i < image->bw->h; ++i)
    image->integral[i] = malloc(image->bw->w * sizeof(int));
}
