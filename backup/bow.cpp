#include "bow.h"
#include "raylib.h"
#include "raymath.h"

#include <vector>
#include <iostream>


void Bow::BowMovement (Vector2 cameraPos, Vector2 mousePos, Vector2 playerPos) {
    
    // Player Direction is caluclated using Vector2Subtract and then normalized
    bowDirection = Vector2Subtract(cameraPos, mousePos);

    // Angle is calulated using atan2
    angle = atan2(bowDirection.y , bowDirection.x);

    // Angle is converted form radients to degrees
    angle = angle * RAD2DEG - 130.0f;
    
    
    // The the center of player is set to the center of the bow
    dest.x = playerPos.x + 0.0f;
    dest.y = playerPos.y + 0.0f;

    std::cout << dest.x << ":" << dest.y << "  "<<  playerPos.x << ":" << playerPos.y << std::endl;

    // For ref
    // DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint);


}

void Bow::ArrowMovement(Vector2 playerPos, Vector2 mousePos)
{
    // Check for input
    if (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(0)) {
        
        // Set arrow positions to bow position
        arrows.postion.x = dest.x;
        arrows.postion.y = dest.y;

        // Set arrow destination rectangle
        arrows.dest.x = arrows.postion.x;
        arrows.dest.y = arrows.postion.y;
        arrows.dest.width = arrowWidth;
        arrows.dest.height = arrowHeight;

        // Calculate the angle for the arrow to point to
        arrows.direction = Vector2Subtract(mousePos, arrows.postion);
        arrows.arrowAngle = atan2(arrows.direction.y, arrows.direction.x);

        // Calculate velocity
        arrows.velocity = Vector2Scale(Vector2Normalize(arrows.direction), arrowSpeed);
        arrows.actualAngle = angle; // Fine-tuned angle you already use

        // Add the arrow to my list of projectiles
        projectiles.push_back(arrows);
    }

    // Loop through all arrows in the projectiles list
    
    
    
}

void Bow::BowDraw(){
    // arrow is drawn on the screen
    DrawTexturePro(Texture, src, dest, (Vector2){width/2, height/2}, angle, WHITE);
    
    for (size_t j = 0; j < projectiles.size(); j++) {
        // Move the arrow
        projectiles[j].postion = Vector2Add(projectiles[j].postion, projectiles[j].velocity);

        // BowUpdate destination rectangle to match position
        projectiles[j].dest.x = projectiles[j].postion.x;
        projectiles[j].dest.y = projectiles[j].postion.y;
        
        DrawTexturePro(
            ArrowTexture,                        // Texture
            {0, 0, 8.0f, 8.0f},                  // Source rectangle
            projectiles[j].dest,                 // Destination rectangle
            {40.0f / 2.0f, 40.0f / 2.0f},        // Origin at center
            projectiles[j].actualAngle,          // Rotation angle
            WHITE                                // Tint
        );
    }

}