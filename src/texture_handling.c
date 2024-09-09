#include "texture_handling.h"
#include <stdio.h>

// Paths to the textures
const char* texture_paths[NUM_TEXTURES] = {
    "textures/wall_texture.png",
    "textures/floor_texture.png",
    "textures/ceiling_texture.png",
    "textures/player_texture.png",
    "textures/enemy_texture.png"
};

// Function to load textures
void load_textures(SDL_Texture *textures[], SDL_Renderer *renderer) {
    for (int i = 0; i < NUM_TEXTURES; i++) {
        SDL_Surface* surface = IMG_Load(texture_paths[i]);
        if (!surface) {
            printf("Failed to load texture: %s, Error: %s\n", texture_paths[i], IMG_GetError());
            continue;
        }
        textures[i] = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        if (!textures[i]) {
            printf("Failed to create texture from surface: %s, Error: %s\n", texture_paths[i], SDL_GetError());
        } else {
            printf("Loaded texture: %s\n", texture_paths[i]);
        }
    }
}

// Function to clean up textures
void cleanup_textures(SDL_Texture *textures[]) {
    for (int i = 0; i < NUM_TEXTURES; i++) {
        if (textures[i]) {
            SDL_DestroyTexture(textures[i]);
            textures[i] = NULL;
            printf("Cleaned up texture %d\n", i);
        }
    }
}
