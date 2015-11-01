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
   t_image *image = load_image(argv[1]);
  printf("Greyscale\n");
  printf("\n\nIntegral image\n");
  for (int y = 0; y < image->bw->h; ++y)
  {
    for (int x = 0; x < image->bw->w; ++x)
    {
      printf("%4lu ", image->integral[y][x]);
    }
    printf("\n");
  }
  printf("\npixels_sum(0, 0, w, h) : %lu\n", pixels_sum(image, 0, 0, image->bw->w, image->bw->h));
  printf("pixels_sum(0, 0, w - 1, h - 1) : %lu\n", pixels_sum(image, 0, 0, image->bw->w - 1, image->bw->h - 1));
  printf("\nComputing features...\n\n");
  compute_features(image, lel);
  fclose(lel);
  free(image);
  return 0;
}
