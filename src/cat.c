#include "cat.h"
// #include <cstddef>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
cat* InitCat()
{
    cat* newcat = (cat*)malloc(sizeof(cat));
    newcat->body = LoadModel("media/cat.obj");
    Texture2D texture = LoadTexture("media/cat.png");
    newcat->bud = NULL;
    newcat->body.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;   
    newcat->position = (Vector3){GetRandomValue(-10,10),GetRandomValue(-10,10),GetRandomValue(-10,10)};
    
    return newcat;
}


void TickCat(cat *rootcat)
{

    int randomvalue = GetRandomValue(0,1000);
    if (randomvalue == 1){
        printf("\nAdding cat\n");
        cat* newcat = InitCat();
        printf("\ninitted\n");
        cat *lastptr = getLastCatPtr(rootcat);
        lastptr->bud = newcat;
        printf("\nshould be added now\n");
        // ????? why is it crashing HERE? 

    }
    printf("done tick");

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