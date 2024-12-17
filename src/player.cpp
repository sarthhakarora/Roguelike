#include "player.h"
#include "raylib.h"

#include <iostream>

void Player::Draw () {
    DrawTexturePro(texture, source, destRect, (Vector2){(float)(width/2), (float)(height/2)}, 0.0f, WHITE);
}
 
void Player::Update () {
    if (IsKeyDown(KEY_W)) {
        destRect.y -= speed;
    }
    if (IsKeyDown(KEY_S)) {
        destRect.y += speed;
    }
    if (IsKeyDown(KEY_D)) {
        destRect.x += speed;
    }
    if (IsKeyDown(KEY_A)) {
        destRect.x -= speed;
    }

 // std::cout << "x  -  " << destRect.x << "   :   " << "y  -  " << destRect.y << std::endl;
}

void Player::Unload() {
    UnloadTexture(texture);
}