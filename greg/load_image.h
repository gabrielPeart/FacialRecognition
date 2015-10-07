#ifndef LOAD_IMAGE_H_
# define LOAD_IMAGE_H_

#include <SDL/SDL.h>

typedef struct s_image t_image;

void            display_image(SDL_Surface *image);
t_image         *load_image(const char *img_name);
void            sleep();

struct          s_image
{
  SDL_Surface   *surface;
  unsigned long **integral;
};

#endif /* !LOAD_IMAGE_H_ */