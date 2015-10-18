#include "load_image.h"
#include "pixel_operations.h"
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <err.h>
#include <assert.h>

void display_image(SDL_Surface *image)
{
  SDL_Surface *screen = NULL;
  SDL_Rect position;

  position.x = 0;
  position.y = 0;

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
  image->bw = convert_to_grey_level(image->surface);
  init_sdl();
  display_image(image->surface);
  display_image(image->bw);
  return image;
}

void init_sdl() {
  if( SDL_Init(SDL_INIT_VIDEO)==-1 )
    errx(1,"Could not initialize SDL: %s.\n", SDL_GetError());
}

SDL_Surface *convert_to_grey_level(SDL_Surface *surface)
{
  Uint32 pixel;
  Uint8 r, g, b, average;
  unsigned h, w;
  SDL_Surface *bw;

  bw = SDL_ConvertSurface(surface, surface->format, surface->flags);
  h = (unsigned)bw->h;
  w = (unsigned)bw->w;
  for (unsigned y = 0; y < h; ++y)
  {
    for (unsigned x = 0; x < w; ++x)
    {
      pixel = getpixel(bw, x, y);
      SDL_GetRGB(pixel, bw->format, &r, &g, &b);
      average = r * 0.3 + g * 0.59 + b * 0.11;
      putpixel(bw, x, y, SDL_MapRGB(bw->format, average, average, average));
    }
  }
  return bw;
}

void sleep() {
  SDL_Event event;

  for (;;) {
    SDL_PollEvent( &event );
    switch (event.type) {
      case SDL_KEYDOWN: return;
      default: break;
    }
  }
}
