#ifndef TEXTURE_HANDLING_H
#define TEXTURE_HANDLING_H
#include <SDL2/SDL.h>

void load_textures(SDL_Texture *textures[], SDL_Renderer *renderer);
void cleanup_textures(SDL_Texture *textures[]);
int get_wall_orientation(); // Declare the function

#endif // TEXTURE_HANDLING_H
