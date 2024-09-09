#ifndef TEXTURE_HANDLING_H
#define TEXTURE_HANDLING_H

#include <SDL2/SDL.h>

extern void load_textures(SDL_Texture *textures[], SDL_Renderer *renderer);
extern void cleanup_textures(SDL_Texture *textures[], int num_textures);

#endif // TEXTURE_HANDLING_H
