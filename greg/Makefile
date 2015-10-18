CC = gcc -std=c99
RM = rm -f

CFLAGS += -Wall -Wextra -pedantic -O3 -lSDL -lSDLmain -lSDL_image

LDFLAGS =

EXEC = main

SRCS =  $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all: $(EXEC)

main: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	@$(RM) $(OBJS)

mrproper: clean
	rm -rf $(EXEC)
