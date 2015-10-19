#include <stdio.h>
#include <err.h>
#include "load_image.h"
#include "integral_image.h"
#include "pixel_operations.h"

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Expect one argument...\n");
    return 1;
  }
  t_image *image = load_image(argv[1]);
  for (int y = 0; y < 4; ++y)
  {
    for (int x = 0; x < 4; ++x)
    {
      printf("%5d | ", getgrey(image->bw, x, y));
    }
    printf("\n");
  }
  printf("\n");
  for (int y = 0; y < 4; ++y)
  {
    for (int x = 0; x < 4; ++x)
    {
      printf("%10lu | ", image->integral[y][x]);
    }
    printf("\n");
  }
  printf("Max : %lu\n", image->integral[1427][2047]);
  free(image);
  return 0;
}
