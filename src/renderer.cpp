#include "renderer.h"

void beginFrame(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 105, 105, 105, 255);
    SDL_RenderClear(renderer);
}

void endFrame(SDL_Renderer* renderer) {
    SDL_RenderPresent(renderer);
}