#include "texture_handling.h"
#include <stdio.h>
#include <SDL2/SDL_image.h> // Include SDL_image header

#define NUM_TEXTURES 5 // Define NUM_TEXTURES
// Paths to the textures
const char* texture_paths[NUM_TEXTURES] = {
    "textures/wall_texture.png",
    "textures/floor_texture.png",
    "textures/ceiling_texture.png",
    "textures/player_texture.png",
    "textures/enemy_texture.png"
};

void load_textures(SDL_Texture *textures[], SDL_Renderer *renderer) {
    for (int i = 0; i < NUM_TEXTURES; i++) {
        SDL_Surface* surface = IMG_Load(texture_paths[i]);
        if (!surface) {
            printf("Failed to load texture: %s, Error: %s\n", texture_paths[i], IMG_GetError());
            textures[i] = NULL;
            continue;
        }
        textures[i] = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (!textures[i]) {
            printf("Failed to create texture from surface: %s, Error: %s\n", texture_paths[i], SDL_GetError());
        }
    }
}

void cleanup_textures(SDL_Texture *textures[], int num_textures) {
    for (int i = 0; i < num_textures; i++) {
        if (textures[i]) {
            SDL_DestroyTexture(textures[i]);
            textures[i] = NULL;
        }
    }
}