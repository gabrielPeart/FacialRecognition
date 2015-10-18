#ifndef OBJECTMARKER_H_
# define OBJECTMARKER_H_

int file_exist (char *filename);
int testoptions();
int checkoptions(int argc, char *argv[]);
int printhowtouse();
void savedMarkedImage(char *imagepath, int width, int height, int marginleft, int margintop);
void init_sdl(void);
SDL_Surface* load_image(char *path);
SDL_Surface* display_image(SDL_Surface *img);

#endif /* !OBJECTMARKER_H_ */
