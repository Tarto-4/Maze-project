CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -Iinc -I/usr/include/SDL2 -g
LDFLAGS = -lSDL2 -lSDL2_image -lm

SRC = src/main.c src/rendering.c src/raycasting.c src/collision_detection.c src/map_parser.c src/input_handling.c src/texture_handling.c
OBJ = $(SRC:.c=.o)

all: my_fps_game

my_fps_game: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ) my_fps_game

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: clean