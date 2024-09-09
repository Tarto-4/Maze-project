#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture_handling.h"  // Include texture handling header file

// Array to hold textures
SDL_Texture *textures[NUM_TEXTURES];

// Global renderer
SDL_Renderer *renderer = NULL;

// Initialize the game
void init_game() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Window *window = SDL_CreateWindow("3D Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        return;
    }

    // Initialize PNG loading
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return;
    }

    // Load textures
    load_textures(textures, renderer);  // Pass renderer to load textures
}

// Clean up the game
void cleanup_game() {
    // Clean up textures
    cleanup_textures(textures);

    // Quit SDL subsystems
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
    SDL_Quit();
}

int main() {
    init_game();

    // Game loop, event handling, etc.
    SDL_Delay(3000);  // Keep the window open for 3 seconds for now

    cleanup_game();
    return 0;
}
