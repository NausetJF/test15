#include "raylib.h"

#ifndef CAT_H
#define CAT_H
typedef struct cat cat;
#include "gamestate.h"
struct cat
{
    Vector3 position;
    Model body;
    struct cat* bud;
    
    /* data */
};

cat* InitCat();

void GameTick(cat *rootcat, gamestate *context);

void MovementTick(cat *rootcat);

void MovementInput(cat *rootcat, float movement_speed);

void CatRun(cat *rootcat);

void moveCat(cat *rootcat, float x, float y, float z);

cat *getLastCatPtr(cat *rootcat);

void UpdateCat();

int CountCats(cat *rootcat);

void DrawCat(cat *rootcat);

#endif // !CAT_H
 