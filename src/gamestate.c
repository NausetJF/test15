#include "gamestate.h"
#include "color.h"



Gamestate InitGameState(void)
{
    Gamestate new_gamestate;
    new_gamestate.points = 1;
    new_gamestate.primary_color = GenRandomColor();
    new_gamestate.camera_pos = (Vector3){0,0,0};
    new_gamestate.running = true;
    new_gamestate.start = true;
    return new_gamestate;
}