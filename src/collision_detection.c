#include <stdio.h>
#include "player.h"
#include "map_parser.h"

extern Player player;

int check_collision(float new_x, float new_y) {
    // Check if new_x and new_y are inside a wall
    if (map[(int)(new_y)][(int)(new_x)] == '1') {
        return 1;  // Collision detected
    }
    return 0;
}

#define MOVE_SPEED 0.1f // Define MOVE_SPEED

void move_player(float delta_x, float delta_y) {
    float new_x = player.x + delta_x * MOVE_SPEED;
    float new_y = player.y + delta_y * MOVE_SPEED;

    if (!check_collision(new_x, player.y)) {
        player.x = new_x;  // Move along the x-axis
    }
    if (!check_collision(player.x, new_y)) {
        player.y = new_y;  // Move along the y-axis
    }
}
