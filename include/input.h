#pragma once

struct InputState {
    float mouseX = 0.0f;
    float mouseY = 0.0f;

    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;

    bool spacePressed = false;
    bool spaceReleased = false;
    bool spaceHeld = false;

    bool leftDown = false;
    bool leftReleased = false;
    bool leftHeld = false;

    bool rightDown = false;
    bool rightReleased = false;
    bool rightHeld = false;
};