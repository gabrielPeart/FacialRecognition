#ifndef SDL_FONCTIONS_H_
# define SDL_FONCTIONS_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <err.h>

SDL_Surface* display_image(SDL_Surface *img);
SDL_Surface* load_image(char *path);
void init_sdl(void);
void wait_for_keypressed(void);

#endif /* !SDL_FONCTIONS_H_ */
