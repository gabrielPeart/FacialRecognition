#ifndef INTEGRAL_IMAGE_H_
# define INTEGRAL_IMAGE_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

int *getIntegralImage(SDL_Surface *image, int *integral, size_t l, size_t c);
void someIntegral(int *integral, size_t l, size_t c, size_t lenght);

#endif /* !INTEGRAL_IMAGE_H_ */
