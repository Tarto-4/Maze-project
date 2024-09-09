#include "game.h"
#include "input_handling.h"
#include "rendering.h"

void game_loop(void) {
    int running = 1;
    while (running) {
        running = handle_input();
        update_game_state();
        render_frame();
        SDL_Delay(16);  // 60 FPS
    }
}
