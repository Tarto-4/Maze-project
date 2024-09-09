# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -Iinc -I/usr/include/SDL2 -g

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Executable
EXEC = $(BIN_DIR)/my_fps_game

# Libraries
LIBS = -lSDL2 -lSDL2_image -lm

# Default target
all: $(EXEC)

# Link the executable
$(EXEC): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Create bin directory if it doesn't exist
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

.PHONY: all clean