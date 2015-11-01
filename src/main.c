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
  t_image *image = load_image(argv[1]);
  /* FILE *lel = NULL; */
  /* lel = fopen("/home/greg/Dropbox/Code/C/FacialRecognition/src/mange.txt", "w+"); */
  /* if (lel == NULL) */
  /*   warn("lelelelelel"); */
  /* fprintf(lel, "%d ", 5); */
  /* compute_features(image, lel); */
  //free(image);
  return 0;
}
