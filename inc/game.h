#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

// Screen resolution
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Player structure
typedef struct {
    float x, y;     // Position of the player
    float angle;    // Direction the player is facing
} Player;

extern Player player;
extern SDL_Renderer *renderer;

// Game initialization
int init_game(void);

// Game loop
void game_loop(void);

// Cleanup game resources
void cleanup_game(void);

#endif
