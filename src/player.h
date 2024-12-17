#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player {
public:
float x = GetScreenWidth()/2;
float y = GetScreenHeight()/2;
float height = 40.0f;
float width = 40.0f;
float speed = 7.0f;
Texture2D texture = LoadTexture("../assets/Tiles/Colored/tile_0004.png");
Rectangle source = {0.0f, 0.0f, 8.0f, 8.0f};
Rectangle destRect = {x, y, width, height};

void Draw();
void Update();
void Unload();
};


#endif 