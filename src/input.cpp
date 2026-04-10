#include <SDL3/SDL.h>
#include "app.h"

void eventHandler(App& app) {
    SDL_Event event;

    app.input.leftDown = false;
    app.input.leftReleased = false;
    app.input.rightDown = false;
    app.input.rightReleased = false;
    app.input.spacePressed = false;
    app.input.spaceReleased = false;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT:
                app.running = false;
                break;

            case SDL_EVENT_WINDOW_RESIZED:
                app.windowWidth = event.window.data1;
                app.windowHeight = event.window.data2;
                break;

            case SDL_EVENT_MOUSE_MOTION:
                app.input.mouseX = event.motion.x;
                app.input.mouseY = event.motion.y;
                break;

            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                if (event.button.button = SDL_BUTTON_LEFT) {
                    app.input.leftDown = true;
                    app.input.leftHeld = true;
                } else if (event.button.button == SDL_BUTTON_RIGHT) {
                    app.input.rightDown = true;
                    app.input.rightHeld = true;
                }
                break;

            case SDL_EVENT_MOUSE_BUTTON_UP:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    app.input.leftReleased = true;
                    app.input.leftHeld = false;
                } else if (event.button.button == SDL_BUTTON_RIGHT) {
                    app.input.rightReleased = true;
                    app.input.rightHeld = false;
                }
                break;

            case SDL_EVENT_KEY_DOWN:
               if (event.key.repeat == 0) {
                if (event.key.scancode == SDL_SCANCODE_SPACE) {
                    app.input.spacePressed = true;
                    app.input.spaceHeld = true;
                } else if (event.key.scancode == SDL_SCANCODE_ESCAPE) {
                    app.running = false;
                }
               }
               break;

            case SDL_EVENT_KEY_UP:
                if (event.key.repeat == 0) {
                    if (event.key.scancode == SDL_SCANCODE_SPACE) {
                        app.input.spaceReleased = true;
                        app.input.spaceHeld = false;
                    }
                }
                break;
        }
    }

    const bool* keystate = SDL_GetKeyboardState(NULL);
    app.input.moveUp = keystate[SDL_SCANCODE_W];
    app.input.moveDown = keystate[SDL_SCANCODE_S];
    app.input.moveRight = keystate[SDL_SCANCODE_D];
    app.input.moveLeft = keystate[SDL_SCANCODE_A];
}