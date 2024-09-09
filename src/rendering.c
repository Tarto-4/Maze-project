#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "rendering.h"
#include "game.h"
#include "texture_handling.h"

SDL_Texture *wall_texture = NULL;

SDL_Texture* load_texture(const char *file, SDL_Renderer *renderer) {
    SDL_Surface *surface = SDL_LoadBMP(file);
    if (!surface) {
        printf("SDL_LoadBMP Error: %s\n", SDL_GetError());
        return NULL;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
    }
    return texture;
}

void load_textures(SDL_Texture *textures[], SDL_Renderer *renderer) {
    textures[0] = load_texture("assets/textures/wall.bmp", renderer);
    if (!textures[0]) {
        printf("Failed to load wall texture\n");
    }
}

void cleanup_textures(SDL_Texture *textures[]) {
    for (int i = 0; textures[i] != NULL; ++i) {
        SDL_DestroyTexture(textures[i]);
    }
}
