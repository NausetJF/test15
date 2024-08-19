#include "gamestate.h"
#include "color.h"


gamestate InitGameState(void)
{
    gamestate new_gamestate;
    new_gamestate.points = 0;
    new_gamestate.primary_color = GenRandomColor();
    return new_gamestate;
}