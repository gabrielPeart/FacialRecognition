#include <stdio.h>
#include "load_image.h"
#include "integral_image.h"

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Expect one argument...\n");
    return 1;
  }
  t_image *image = load_image(argv[1]);
  integral_image(image);
  printf("total pixel number : %lu\n", pixels_sum(image, 0, 0, 2, 2));
  return 0;
}
