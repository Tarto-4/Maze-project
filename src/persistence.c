#include "persistence.h"
#include <stdio.h>

void save_game_state(const char *file_path) {
    FILE *file = fopen(file_path, "w");
    if (!file) {
        printf("Failed to save game state\n");
        return;
    }
    fprintf(file, "%d %d %f\n", player.x, player.y, player.angle);  // Example of saving player data
    fclose(file);
}

void load_game_state(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        printf("No saved game state found, starting fresh\n");
        return;
    }
    fscanf(file, "%d %d %f", &player.x, &player.y, &player.angle);
    fclose(file);
}
