#include "load_image.h"
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <err.h>

void display_image(SDL_Surface *image)
{
  SDL_Surface *screen = NULL;
  SDL_Rect position;

  position.x = 0;
  position.y = 0;

  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_SetVideoMode(image->w, image->h, 32, SDL_HWSURFACE);
  SDL_BlitSurface(image, NULL, screen, &position);
  SDL_Flip(screen);
  sleep();
}

t_image *load_image(const char *img_name)
{
  t_image *image;

  image = malloc(sizeof(image));
  image->surface = IMG_Load(img_name);
  if (!image->surface)
  {
    warn("%s ", img_name);
    return NULL;
  }
  //display_image(image->surface);
  return image;
}

void sleep()
{
  char b = 1;
  SDL_Event event;

  while (b)
  {
    SDL_WaitEvent(&event);
    if (event.type == SDL_QUIT)
      b = 0;
  }
}
