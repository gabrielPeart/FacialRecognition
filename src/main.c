#include <stdio.h>
#include <err.h>
#include "load_image.h"
#include "haar_features.h"

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Expect one argument...\n");
    return 1;
  }
  
  FILE *lel = fopen("mange.txt", "a+");
  if (lel == NULL)
    warn("lelelelelel");
  fprintf(lel, "%d ", 5);
  t_image *image = load_image(argv[1]);
  compute_features(image, lel);
  fclose(lel);
  free(image);
  return 0;
}
