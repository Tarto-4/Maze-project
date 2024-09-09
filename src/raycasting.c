#include "raycasting.h"
#include "game.h"
#include "map_parser.h"
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include "texture_handling.h"

extern SDL_Rect wall_rect; // Declare wall_rect as an external variable if defined elsewhere

void render_scene(SDL_Renderer *renderer, SDL_Texture *textures[]) {
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        // Perform raycasting and render textured walls based on orientation
        // Simplified example logic:
        int texture_index = get_wall_orientation();  // Function to get the texture based on the wall's orientation
        SDL_RenderCopy(renderer, textures[texture_index], NULL, &wall_rect);  // Render wall using the correct texture
    }
}

// Variables to track the player's position and direction
extern Player player;
extern SDL_Renderer *renderer;

#define FOV 60.0  // Field of view in degrees
#define MAX_DEPTH 20

void perform_raycasting() {
    float ray_angle;
    float ray_x, ray_y;
    float distance_to_wall;
    int wall_hit;

    float camera_plane = tan(FOV * M_PI / 180.0 / 2); // Camera plane based on FOV
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        // Calculate the current ray's angle
        ray_angle = player.angle + atan((2 * x / (float)SCREEN_WIDTH - 1) * camera_plane);

        // Set initial position for the ray (from the player)
        ray_x = player.x;
        ray_y = player.y;

        distance_to_wall = 0;
        wall_hit = 0;

        while (!wall_hit && distance_to_wall < MAX_DEPTH) {
            distance_to_wall += 0.1; // Step size for raycasting

            ray_x = player.x + cos(ray_angle) * distance_to_wall;
            ray_y = player.y + sin(ray_angle) * distance_to_wall;

            // Check if the ray has hit a wall
            if (map[(int)ray_y][(int)ray_x] == '1') {
                wall_hit = 1;
            }
        }

        // Calculate the projected wall height
        int line_height = (int)(SCREEN_HEIGHT / distance_to_wall);

        // Determine color based on wall direction
        SDL_Color wall_color = {200, 0, 0, 255}; // Default red
        if (fabs(ray_angle - player.angle) < 0.1) {
            wall_color.r = 255;  // Front-facing walls
        }

        // Draw the wall slice
        SDL_SetRenderDrawColor(renderer, wall_color.r, wall_color.g, wall_color.b, 255);
        SDL_RenderDrawLine(renderer, x, (SCREEN_HEIGHT / 2) - (line_height / 2), x, (SCREEN_HEIGHT / 2) + (line_height / 2));
    }
}
