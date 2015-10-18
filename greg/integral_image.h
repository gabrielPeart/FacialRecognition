#ifndef INTEGRAL_IMAGE_H_
# define INTEGRAL_IMAGE_H_

#include <SDL/SDL.h>
#include "load_image.h"

void            integral_image(t_image *image);
void            init_integral_image(t_image *image);
unsigned long   pixels_sum(t_image *image, int x, int y, int width, int height);

#endif /* !INTEGRAL_IMAGE_H_ */
