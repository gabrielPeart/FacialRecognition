#include "objectMarker.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char savingfile[128] = "";
static char imagefolder[128] = "";

int main(int argc, char *argv[])
{
  if(checkoptions(argc, argv) == 0) return 0;
  if(testoptions() == 0) return 0;
  init_sdl();
  
  //char *lol = "images/myimage.jpg";
  //savedMarkedImage(lol, 0, 0, 0, 0);
  return 0;
}

void init_sdl(void) {
  // Init only the video part
  if( SDL_Init(SDL_INIT_VIDEO)==-1 ) {
    // If it fails, die with an error message
    errx(1,"Could not initialize SDL: %s.\n", SDL_GetError());
  }
  // We don't really need a function for that ...
}

SDL_Surface* load_image(char *path) {
  SDL_Surface          *img;
  // Load an image using SDL_image with format detection
  img = IMG_Load(path);
  if (!img)
    // If it fails, die with an error message
    errx(3, "can't load %s: %s", path, IMG_GetError());
  return img;
}

SDL_Surface* display_image(SDL_Surface *img) {
  SDL_Surface          *screen;
  // Set the window to the same size as the image
  screen = SDL_SetVideoMode(img->w, img->h, 0, SDL_SWSURFACE|SDL_ANYFORMAT);
  if ( screen == NULL ) {
    // error management
    errx(1, "Couldn't set %dx%d video mode: %s\n",
         img->w, img->h, SDL_GetError());
  }
 
  /* Blit onto the screen surface */
  if(SDL_BlitSurface(img, NULL, screen, NULL) < 0)
    warnx("BlitSurface error: %s\n", SDL_GetError());
 
  // Update the screen
  SDL_UpdateRect(screen, 0, 0, img->w, img->h);
 
  // wait for a key
  wait_for_keypressed();
 
  // return the screen for further uses
  return screen;
}


void savedMarkedImage(char *imagepath, int width, int height, int marginleft, int margintop)
{
  FILE *file = fopen(savingfile, "r+");
  if (file != NULL) {  // We write the new object positions in the saving file
    char str[strlen(imagepath) + 50];
    sprintf(str, "%s %d %d %d %d\n", imagepath, marginleft, margintop, width, height);
    fseek(file, 0, SEEK_END);
    fputs(str, file);
    fclose(file);
  }
  else {
    // Throw an error...
  }
}

int printhowtouse()
{
  printf("objectMarker : created by Paul Semel for an end year project with his awesome team. It is used to mark an image of precise object.\n");
  printf("This tool is often used when you want to create a classifier for an object recognition in an image.\n\n");
  printf("usage : ./objectmarker --folder /path/to/folder/containing/images --file /path/to/file/where/to/write/informations\n\n");
  return 0;
}

int checkoptions(int argc, char *argv[])
{
  if(argc < 2) return printhowtouse();
  else if(argc >= 2)
  {
    for(int i = 1; i < argc; i++)
    {
      if(strcmp(argv[i], "help") == 0)
          return printhowtouse();
      else if(strcmp(argv[i], "--help") == 0)
          return printhowtouse();
      else if(strcmp(argv[i], "-h") == 0)
          return printhowtouse();
      else if(strcmp(argv[i], "--folder") == 0)
        {
          if(i + 1 < argc && sizeof(argv[i + 1]) <= 128)
          {
            strcpy(imagefolder, argv[i + 1]);
            i++;
          }
          else return printhowtouse();
        }
      else if (strcmp(argv[i], "--file") == 0)
        {
          if(i + 1 < argc && sizeof(argv[i + 1]) <= 128)
          {
            strcpy(savingfile, argv[i + 1]);
            i++;
          }
          else return printhowtouse();
        }
      else
        {
          printf("Unknown command : %s\n", argv[i]);
          return printhowtouse();
        }
    }
  }
  return 1;
}

int testoptions()
{
  if(strcmp(savingfile, "") == 0 || strcmp(imagefolder, "") == 0)
  {
    return printhowtouse();
  }
  if(file_exist(savingfile) == 0)
  {
    FILE *file = fopen(savingfile, "ab+");
    fclose(file);
  }
  return 1;
}

int file_exist (char *filename)
{
  FILE *file;
  file = fopen(filename, "r");
  if(file != NULL)
    {
      fclose(file);
      return 1;
    }
  return 0;
}
