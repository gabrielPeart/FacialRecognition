CC = gcc -std=c99
RM = rm -f

CFLAGS += -Wall -Wextra -pedantic -O0 -lSDL -lSDLmain -lSDL_image

LDFLAGS = -lm

EXEC = main

SRCS =  $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all: $(EXEC)

main: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	@$(RM) $(OBJS)

mrproper: clean
	rm -rf $(EXEC) *.d *.o main
