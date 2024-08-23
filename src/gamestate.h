#include "raylib.h"
#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "color.h"
#define ALLEY_X 20

struct Gamestate
{
    int points;
    Color primary_color;
    Color secondary_color;
    Vector3 camera_pos;
    bool running;
    bool start;
    /* data */
};

typedef struct Gamestate Gamestate;

Gamestate InitGameState(void);

#endif // !GAMESTATE_H
