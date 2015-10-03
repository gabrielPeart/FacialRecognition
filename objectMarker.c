#include "objectMarker.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char savingfile[128] = "";
static char imagefolder[128] = "";

void savedMarkedImage(char *imagepath, int width, int height, int marginleft, int margintop);
int printhowtouse();
int checkoptions(int argc, char *argv[]);
int testoptions();
int file_exist (char *filename);

int main(int argc, char *argv[])
{
  if(checkoptions(argc, argv) == 0) return 0;
  if(testoptions() == 0) return 0;
  //char *lol = "images/myimage.jpg";
  //savedMarkedImage(lol, 0, 0, 0, 0);
  return 0;
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
