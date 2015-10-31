#ifndef LOAD_IMAGE_H_
# define LOAD_IMAGE_H_

#include <SDL/SDL.h>

typedef struct s_image t_image;

void            display_image(SDL_Surface *image);
t_image        *load_image(const char *img_name);
void            init_sdl();
SDL_Surface    *convert_to_grey_level(SDL_Surface *surface);
void            sleep();
char           *file_name(const char *path);

struct                  s_image
{
    SDL_Surface         *surface;
    SDL_Surface         *bw;
    unsigned long      **integral;
    const char          *path;
    FILE                *haar_results;
};

#endif /* !LOAD_IMAGE_H_ */
