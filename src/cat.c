#include "cat.h"
// #include <cstddef>
#include <stddef.h>
#include <stdio.h>

cat InitCat()
{
    cat newcat;
    newcat.body = LoadModel("media/cat.obj");
    Texture2D texture = LoadTexture("media/cat.png");
    newcat.body.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;   
    newcat.position = (Vector3){GetRandomValue(-5,5),GetRandomValue(-5,5),GetRandomValue(-5,5)};
    
    return newcat;
}


void TickCat(cat *rootcat)
{

    int randomvalue = GetRandomValue(0,100);
    if (randomvalue == 60){
        printf("\nAdding cat\n");
        cat newcat = InitCat();
        *rootcat->bud = newcat;
    }


}

void UpdateCat()
{
}

void DrawCat(cat *rootcat)
{
    DrawModel(rootcat->body,rootcat->position,1.0f,WHITE);
    printf("\ngetting pointer...\n");
    cat *budptr = rootcat->bud;
    if (budptr == NULL){
        
    }
    else{
        printf("drawing cat bud");
        DrawCat(budptr);
    }
}
