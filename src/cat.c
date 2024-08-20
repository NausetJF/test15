#include "cat.h"
// #include <cstddef>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "gamestate.h"
cat* InitCat()
{
    cat* newcat = (cat*)malloc(sizeof(cat));
    newcat->body = LoadModel("media/cat.obj");
    Texture2D texture = LoadTexture("media/cat.png");
    newcat->bud = NULL;
    newcat->body.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;   
    newcat->position = (Vector3){GetRandomValue(-10,10),GetRandomValue(-10,10),GetRandomValue(-100,-50)};
    
    return newcat;
}


void GameTick(cat *rootcat, gamestate *context)
{

    int randomvalue = GetRandomValue(0,1);
    if (randomvalue == 1){
        printf("\nAdding cat\n");
        cat* newcat = InitCat();
        printf("\ninitted\n");
        cat *lastptr = getLastCatPtr(rootcat);
        lastptr->bud = newcat;
        printf("\nshould be added now\n");
        // ????? why is it crashing HERE? 
        context->points += 1;
    }

    float movement_speed = 0.5f;

    if (IsKeyDown(KEY_D))
    {
        moveCat(rootcat,-movement_speed,0.0f,0.0f);
        /* code */
    }
    if (IsKeyDown(KEY_A))
    {
        moveCat(rootcat,+movement_speed,0.0f,0.0f);
        /* code */
    }
    
    if (IsKeyDown(KEY_W))
    {
        moveCat(rootcat,0.0f,-movement_speed,0.0f);
        /* code */
    }
    
    
    if (IsKeyDown(KEY_S))
    {
        moveCat(rootcat,0.0f,+movement_speed,0.0f);
        /* code */
    }
    

    CatRun(rootcat);
    
    
    printf("done tick");
}

void CatRun(cat *rootcat)
{
    moveCat(rootcat, 0, 0, 2);
}

void moveCat(cat *rootcat, float x, float y,float z)
{
    cat *current = rootcat;

    while (current->bud != NULL)
    {
        current->position.x = current->position.x + x;
        current->position.y = current->position.y + y;
        current->position.z = current->position.z + z;
        current = current->bud;
        /* code */
    }
    
}

cat* getLastCatPtr(cat *rootcat){
      // printf("\n start drawing...\n");
    printf("current");
    cat* current = rootcat;
    printf("while loop starting");
    while (current->bud != NULL)
    {
        // printf("past condition");
        current = current->bud;
        /* code */
    }
    
    return current;
    


    // shit code;

    // if (&(rootcat) == NULL) {
    //     printf("something weird happened\n");
    //     return NULL;
    // }
    // cat *last_cat = rootcat;

    // // DrawModel(rootcat->body, rootcat->position, 1.0f, WHITE);
    // printf("\ndone_getting last...\n");
    // printf("\ncheck...\n");
    // if (&(last_cat->bud) == NULL) {
    //     printf("\nif statement satisfied...\n");
    //     return last_cat;
    // }
    // printf("\nrecurring...\n");
    // last_cat = getLastCatPtr((last_cat->bud));
    // printf("next...");
    // // return last_cat;
}

void UpdateCat()
{
}

int CountCats(cat *rootcat){
    // printf("\n start drawing...\n");
    printf("counting started current");
    cat* current = rootcat;
    printf("while loop starting");
    int newcount = 0;
    while (current->bud != NULL)
    {
        // printf("past condition");
        // DrawModel(current->body,current->position,1.0f,WHITE);
        newcount += 1;
        current = current->bud;
    
        /* code */
    }
    return newcount;
}

void DrawCat(cat *rootcat)
{
    printf("DRAWing started current");
    cat* current = rootcat;
    printf("while loop starting");
    
    while (current->bud != NULL)
    {
        // printf("past condition");
        DrawModel(current->body,current->position,1.0f,WHITE);

        current = current->bud;
    
        /* code */
    }
    
    // return current;
    
    
    // printf("\n start drawing...\n");
    // if (&(rootcat) == NULL) {
    //     printf("rootcat is NULL\n");
    //     return;
    // }


    // DrawModel(rootcat->body, rootcat->position, 1.0f, WHITE);
    // printf("\ndone drawing...\n");
    // if (&(rootcat->bud) != NULL) {
    //     return;
    // }
    // DrawCat(&rootcat->bud);
}