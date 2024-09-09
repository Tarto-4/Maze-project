#include "texture_loader.h"
#include <SDL2/SDL_image.h>
#include "texture_handling.h"

SDL_Texture *load_texture(const char *file_path, SDL_Renderer *renderer) {
    SDL_Texture *texture = IMG_LoadTexture(renderer, file_path);
    if (!texture) {
        printf("Failed to load texture: %s\n", file_path);
    }
    return texture;
}
