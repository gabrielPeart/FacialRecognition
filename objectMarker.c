#include "objectMarker.h"
#include <stdlib.h>
#include <stdio.h>

static char *savingfile;

int main(int argc, char *argv[])
{
  
  return 0;
}

void savedMarkedImage(char *imagepath, int width, int heigh, int marginleft, int margintop)
{
  FILE *file = fopen(savingfile, "r+");
  if (file != NULL) {  // We write the new object positions in the saving file
    fseek(file, 0, SEEK_END);
    fputs("", file);
  }
  else {
    // Throw an error...
  }
}
