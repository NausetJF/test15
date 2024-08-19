#include "raylib.h"
#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "color.h"
struct gamestate
{
    int points;
    Color primary_color; 
    Color secondary_color; 

    /* data */
};

typedef struct gamestate gamestate;



gamestate InitGameState(void);


#endif // !GAMESTATE_H

