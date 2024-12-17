#ifndef CAMERA_H
#define CAMERA_H

#include "raylib.h"
#include "player.h"

class GameCamera{
public:
    Camera2D camera = { 0 };
    float x = 0;
    float y = 0;

    
    void camUpdate();
};

#endif