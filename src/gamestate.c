#include "gamestate.h"
#include "color.h"



gamestate InitGameState(void)
{
    gamestate new_gamestate;
    new_gamestate.points = 0;
    new_gamestate.primary_color = GenRandomColor();
    new_gamestate.camera_pos = (Vector3){0,0,0};

    return new_gamestate;
}