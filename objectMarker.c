#include "objectMarker.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char *savingfile = "test.txt";
void savedMarkedImage(char *imagepath, int width, int height, int marginleft, int margintop);

int main(int argc, char *argv[])
{
  char *lol = "images/myimage.jpg";
  savedMarkedImage(lol, 0, 0, 0, 0);
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
