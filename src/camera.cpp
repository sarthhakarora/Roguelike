#include "camera.h"
#include "player.h"

void GameCamera::camUpdate()
{
    camera.target = (Vector2){x, y};
    camera.offset = (Vector2){400, 300};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;


}
