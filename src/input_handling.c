#include "input_handling.h"
#include "collision_detection.h"
#include <SDL2/SDL.h>
#include <math.h>
#include "player.h"

extern void move_player(float delta_x, float delta_y); // Ensure this function is declared

int handle_input(SDL_Event *event) {
    while (SDL_PollEvent(event)) {
        switch (event->type) {
            case SDL_QUIT:
                return 0;
            case SDL_KEYDOWN:
                switch (event->key.keysym.sym) {
                    case SDLK_w:
                        move_player(cos(player.angle), sin(player.angle));  // Move forward
                        break;
                    case SDLK_s:
                        move_player(-cos(player.angle), -sin(player.angle));  // Move backward
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    return 1;
}