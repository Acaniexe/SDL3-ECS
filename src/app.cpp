#include "app.h"
#include "renderer.h"
#include <iostream>


bool init(App& app) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL failed: " << SDL_GetError() << std::endl;
        return false;
    }

     app.window = SDL_CreateWindow("Testing", 900, 900, SDL_WINDOW_RESIZABLE);
    if (!app.window) {
        std::cout << "Window failed: " << SDL_GetError() << std::endl;
        return false;
    }

     app.renderer = SDL_CreateRenderer(app.window, NULL);
    if (!app.renderer) {
        std::cout << "Renderer failed: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void update(App& app, double deltaTime) {
    //update logic goes here
    app.movementSystem.update(app.entityManager, deltaTime);
}

void render(App& app) {
    beginFrame(app.renderer);

    for (auto& [entityId, components] : app.entityManager.getEntities()) {
        Entity entity(entityId);
        auto* position = app.entityManager.getComponent<Position> (entity);
        if (position) {
            SDL_SetRenderDrawColor(app.renderer, 0, 0, 255, 255);

            SDL_FRect rect = {position->x, position->y, 50.0f, 50.0f};
            SDL_RenderFillRect(app.renderer, &rect);
        }
    }

    endFrame(app.renderer);
}

void cleanUp(App& app) {
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();
}