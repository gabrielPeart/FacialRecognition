#include <stdio.h>
#include "load_image.h"

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Expect one argument...\n");
    return 1;
  }
  load_image(argv[1]);
  return 0;
}
