#include "texture_handling.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

// Function prototypes
void render_scene(SDL_Renderer *renderer);
SDL_Texture* load_texture(const char *file, SDL_Renderer *renderer);

// Example global texture variable
SDL_Texture *wall_texture = NULL;

SDL_Texture* load_texture(const char *file, SDL_Renderer *renderer) {
    SDL_Surface *surface = IMG_Load(file);
    if (!surface) {
        printf("Failed to load texture: %s, Error: %s\n", file, IMG_GetError());
        return NULL;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        printf("Failed to create texture from surface: %s, Error: %s\n", file, SDL_GetError());
    }
    return texture;
}

void render_scene(SDL_Renderer *renderer) {
    // Example rendering code
    SDL_RenderClear(renderer);
    if (wall_texture) {
        SDL_RenderCopy(renderer, wall_texture, NULL, NULL);
    }
    SDL_RenderPresent(renderer);
}

// Example of other rendering-related functions
void initialize_rendering(SDL_Renderer *renderer) {
    wall_texture = load_texture("textures/wall_texture.png", renderer);
    // Initialize other textures and rendering-related resources
}

void cleanup_rendering() {
    if (wall_texture) {
        SDL_DestroyTexture(wall_texture);
        wall_texture = NULL;
    }
    // Clean up other textures and rendering-related resources
}