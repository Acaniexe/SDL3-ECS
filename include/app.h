#pragma once
#include <SDL3/SDL.h>
#include "input.h"
#include "ECS.h"
#include "components/movement.h"

struct App {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    int windowWidth = 900;
    int windowHeight = 900;
    bool running = true;
    
    InputState input;

    EntityManager entityManager;
    MovementSystem movementSystem;
};

bool init(App& app);
void eventHandler(App& app);
void update(App& app, double deltaTime);
void render(App& app);
void cleanUp(App& app);