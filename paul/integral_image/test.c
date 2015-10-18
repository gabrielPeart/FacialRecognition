#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL_fonctions.h"
#include "integral_image.h"

void print_table(int *table, size_t l, size_t c)
{
  for(size_t i = 0; i < l; i++)
  {
    for(size_t j = 0; j < c; j++)
      printf("%d | ", *(table + (i * c) + j));
    printf("|");
  }
}

int main()
{
  init_sdl();
  SDL_Surface *image = load_image("test.png");
  /* Normalement on envoie l'image en noir/blanc */
  size_t l = image->h;
  size_t c = image->w;
  int *integral;
  integral = malloc(sizeof(int) * l * c);
  integral = getIntegralImage(image, integral, l, c);
  print_table(integral, l, c);
  return 0;
}
