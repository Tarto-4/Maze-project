#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include <SDL2/SDL.h>

// Function to load texture from file
SDL_Texture *load_texture(const char *file_path, SDL_Renderer *renderer);

#endif
