#include "bow.h"
#include "raylib.h"
#include "raymath.h"

#include <vector>
#include <iostream>


void Bow::BowMovement (Vector2 cameraPos, Vector2 mousePos) {
    
    // Player Direction is caluclated using Vector2Subtract and then normalized
    bowDirection = Vector2Subtract(cameraPos, mousePos);

    // Angle is calulated using atan2
    angle = atan2(bowDirection.y , bowDirection.x);

    // Angle is converted form radients to degrees
    angle = angle * RAD2DEG - 130.0f;
    
    // Player is drawn on the screen
    DrawTexturePro(Texture, src, dest, (Vector2){width/2, height/2}, angle, WHITE);
    
    // The the center of player is set to the center of the bow
    dest.x = cameraPos.x + 0.0f;
    dest.y = cameraPos.y + 0.0f;

    // For ref
    // DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint);


}

void Bow::ArrowMovement(Vector2 playerPos, Vector2 mousePos)
{
    //Check for input
    if (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(0)) {
        
        // Set arrow postions to bow postion
        arrows.postion.x = dest.x;
        arrows.postion.y = dest.y;

        // Calulate the angle for the arrow to point to
        arrows.direction = Vector2Subtract(mousePos, arrows.postion);
        arrows.arrowAngle = atan2(arrows.direction.y, arrows.direction.x);

        // Calulate Veclocity
        arrows.velocity = Vector2Scale(Vector2Normalize(arrows.direction), 7.0f);
        arrows.actualAngle = angle;

        // Add the arrow to my list of projectiles
        projectiles.push_back(arrows);
    }

    // Loop through all arrows in the projectiles list
    for (size_t i = 0; i < projectiles.size(); i++) {
        // Move the arrow
        projectiles[i].postion = Vector2Add(projectiles[i].postion, projectiles[i].velocity);
        
        // Testing
        //std::cout << "Angle: " << projectiles[i].arrowAngle << std::endl;
        
        // Draw the Texture
        DrawTextureEx(ArrowTexture, projectiles[i].postion, projectiles[i].actualAngle, 5.0f, WHITE);
    }
}

