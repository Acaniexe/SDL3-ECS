#include "app.h"
#include "components/position.h"
#include "components/velocity.h"

int main(int argc, char *argv[]) {
    App app;

    if (!init(app)) return 1;

    Entity player = app.entityManager.createEntity();
    app.entityManager.addComponent(player, Position{0.0f, 0.0f});
    app.entityManager.addComponent(player, Velocity{50.0f, 50.0f});

    Entity enemy = app.entityManager.createEntity();
    app.entityManager.addComponent(enemy, Position{20.0f, 0.0f});
    app.entityManager.addComponent(enemy, Velocity{25.0f, 20.0f});
    
    Uint64 perFrequency = SDL_GetPerformanceFrequency();
    Uint64 lastCounter = SDL_GetPerformanceCounter();

    while (app.running) {
        Uint64 currentCounter = SDL_GetPerformanceCounter();
        double deltaTime = (double)(currentCounter - lastCounter) / (double)(perFrequency);
        lastCounter = currentCounter;

        eventHandler(app);
        update(app, deltaTime);
        render(app);
    }

    cleanUp(app);
    return 0;
}