#include "ui.h"
#include "gamestate.h"
#include "raylib.h"

void RenderUI(Gamestate *context)
{
    if (context->running == false && context->start == true)
    {
        DrawRectangle(GetScreenHeight(),GetScreenWidth(),GetScreenHeight()/2,GetScreenWidth()/2,(Color){255,000,000,124});
        DrawText("GAME OVER",400,400,50,RED);
        /* code */
    }
    
}