#include "../headers/header.h"
#include <math.h>  // Include the math library

/**
 * changeColorIntensity - change color intensity
 * based on a factor value between 0 and 1
 * @color: pointer to the color to be modified
 * @factor: intensity factor
 */
void changeColorIntensity(color_t *color, float factor)
{
    color_t a = (*color & 0xFF000000);
    color_t r = ((*color & 0x00FF0000) >> 16) * factor;
    color_t g = ((*color & 0x0000FF00) >> 8) * factor;
    color_t b = (*color & 0x000000FF) * factor;
    *color = a | (r << 16) | (g << 8) | b;
}

/**
 * renderFloor - render floor
 * @x: x coordinate
 * @y: y coordinate
 * @distance: distance
 * @rays: array of rays
 * @player: player structure
 */
void renderFloor(int x, int y, double distance, ray_t *rays, player_t player)
{
    int textureOffsetY = (int)fabs((distance * sin(rays[x].rayAngle)) + player.y);
    int textureOffsetX = (int)fabs((distance * cos(rays[x].rayAngle)) + player.x);

    // Your rendering code here...
    drawPixel(x, y, getTextureColor(floorTexture, textureOffsetX, textureOffsetY));
}

/**
 * renderCeil - render ceiling
 * @x: x coordinate
 * @y: y coordinate
 * @distance: distance
 * @rays: array of rays
 * @player: player structure
 */
void renderCeil(int x, int y, double distance, ray_t *rays, player_t player)
{
    int textureOffsetY = (int)fabs((-distance * sin(rays[x].rayAngle)) + player.y);
    int textureOffsetX = (int)fabs((-distance * cos(rays[x].rayAngle)) + player.x);

    // Your rendering code here...
    drawPixel(x, y, getTextureColor(ceilTexture, textureOffsetX, textureOffsetY));
}