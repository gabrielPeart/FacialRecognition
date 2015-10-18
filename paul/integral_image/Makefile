## Simple SDL mini code
 
CC=gcc
 
CPPFLAGS= `pkg-config --cflags sdl`
CFLAGS= -Wall -Wextra -std=c99 -O3
LDFLAGS=
LDLIBS= `pkg-config --libs sdl` -lSDL_image
 
SRC= pixel_operations.c SDL_fonctions.c integral_image.c test.c
OBJ= ${SRC:.c=.o}
 
all: test
 
test: ${OBJ}
 
clean:
	rm -f *~ *.o *.d
	rm -f test
 
# END
