#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "texture_handling.h"  // Include texture handling header file
#include "config.h"
#include "game.h"

// Define the player variable
SDL_Point player = {0, 0}; // Initialize as needed

// Array to hold textures
SDL_Texture *textures[NUM_TEXTURES];

// Global renderer
SDL_Renderer *renderer = NULL;

// Declare the load_texture function
SDL_Texture* load_texture(const char* file, SDL_Renderer* renderer);

// Declare the cleanup_game function
void cleanup_game();

void init_game() {
    // Initialize SDL and create a window and renderer
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Window* window = SDL_CreateWindow("My FPS Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    // Load textures from the assets directory
    textures[0] = load_texture("assets/wall_texture.png", renderer);
    textures[1] = load_texture("assets/floor_texture.png", renderer);
    textures[2] = load_texture("assets/ceiling_texture.png", renderer);
    textures[3] = load_texture("assets/player_texture.png", renderer);
    textures[4] = load_texture("assets/enemy_texture.png", renderer);

    // Check if any texture failed to load
    for (int i = 0; i < NUM_TEXTURES; i++) {
        if (!textures[i]) {
            fprintf(stderr, "Failed to load one or more textures.\n");
            cleanup_game();
            SDL_Quit();
            return;
        }
    }
}

void cleanup_game() {
    cleanup_textures(textures, NUM_TEXTURES);
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    (void)argc; // Suppress unused parameter warning
    (void)argv; // Suppress unused parameter warning

    init_game();

    // Game loop, event handling, etc.
    SDL_Delay(3000);  // Keep the window open for 3 seconds for now

    cleanup_game();
    return 0;
}