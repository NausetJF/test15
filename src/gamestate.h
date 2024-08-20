#include "raylib.h"
#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "color.h"
#define ALLEY_X 20

struct gamestate
{
    int points;
    Color primary_color; 
    Color secondary_color; 
    Vector3 camera_pos;
    /* data */
};

typedef struct gamestate gamestate;



gamestate InitGameState(void);


#endif // !GAMESTATE_H

