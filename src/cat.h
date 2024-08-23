#include "raylib.h"

#ifndef CAT_H
#define CAT_H
typedef struct Cat Cat;
#include "gamestate.h"
struct Cat
{
    Vector3 position;
    Model body;
    struct Cat *bud;

    /* data */
};

Cat *InitCat();

void CatTick(Cat *rootcat, Gamestate *context, Camera3D *camera);

void CheckCollisions(Cat *rootcat, Gamestate *context, Camera3D *camera);

void AddCat(Cat *rootcat, Gamestate *context);

bool CatCollided(Cat *rootcat, Gamestate *context, Camera3D *camera);

void MovementTick(Cat *rootcat);

void MovementInput(Cat *rootcat, float movement_speed);

void CatRun(Cat *rootcat);

void moveCat(Cat *rootcat, float x, float y, float z);

Cat *getLastCatPtr(Cat *rootcat);

void UpdateCat();

int CountCats(Cat *rootcat);

void DrawCat(Cat *rootcat);

void ClearCatsBehindCamera(Cat *rootcat,Camera3D *camera,Gamestate *context);

void deleteCat(Cat *rootcat, Cat *target);

#endif // !CAT_H
