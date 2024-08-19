#include "raylib.h"

#ifndef CAT_H
#define CAT_H
typedef struct cat cat;

struct cat
{
    Vector3 position;
    Model body;
    struct cat* bud;
    
    /* data */
};

cat* InitCat();

void TickCat(cat *rootcat);

cat* getLastCatPtr(cat *rootcat);

void UpdateCat();

int CountCats(cat *rootcat);

void DrawCat(cat *rootcat);

#endif // !CAT_H
 