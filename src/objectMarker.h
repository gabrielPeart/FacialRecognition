#ifndef OBJECTMARKER_H_
# define OBJECTMARKER_H_

#include <SDL/SDL.h>

int     file_exist (char *filename);
int     testoptions();
int     checkoptions(int argc, char *argv[]);
int     printhowtouse();
void    savedMarkedImage(char *imagepath, int width, int height, int marginleft, int margintop);

#endif /* !OBJECTMARKER_H_ */
