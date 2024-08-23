#include "cat.h"
// #include <cstddef>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "raymath.h"
#include "gamestate.h"
Cat *InitCat()
{
    Cat *newcat = (Cat *)malloc(sizeof(Cat));
    newcat->body = LoadModel("media/cat.obj");
    Texture2D texture = LoadTexture("media/cat.png");
    newcat->bud = NULL;
    newcat->body.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    newcat->position = (Vector3){GetRandomValue(-10, 10), GetRandomValue(-10, 10), GetRandomValue(-100, -50)};

    return newcat;
}

void CatTick(Cat *rootcat, Gamestate *context, Camera3D *camera)
{

    if (context->running)
    {
        AddCat(rootcat, context);
        CheckCollisions(rootcat, context, camera);

        CatRun(rootcat);

        /* code */
    }
    ClearCatsBehindCamera(rootcat, camera, context);
    printf("done tick");
}

void CheckCollisions(Cat *rootcat, Gamestate *context, Camera3D *camera)
{
    if (CatCollided(rootcat, context, camera))
    {
        context->running = false;
    }
}

void AddCat(Cat *rootcat, Gamestate *context)
{
    for (int i = 0; i < context->points; i++)
    {
        int randomvalue = GetRandomValue(0, 100);
        if (randomvalue == 1)
        {
            printf("\nAdding cat\n");
            Cat *newcat = InitCat();
            printf("\ninitted\n");
            Cat *lastptr = getLastCatPtr(rootcat);
            lastptr->bud = newcat;
            printf("\nshould be added now\n");
        }
    }
}

bool CatCollided(Cat *rootcat, Gamestate *context, Camera3D *camera)
{

    Cat *current = rootcat;

    while (current->bud != NULL)
    {
        // printf("past condition");
        BoundingBox box = GetModelBoundingBox(current->body);
        Vector3 position = current->position;
        box.min = Vector3Add(box.min, position);
        box.max = Vector3Add(box.max, position);

        DrawBoundingBox(box, WHITE);
        if (CheckCollisionBoxSphere(box, camera->position, 0.01f))
        {
            context->running = false;
            printf("\n\n\nHIT!!\n\n\n");
            return true;
            /* code */
        }
        current = current->bud;

        /* code */
    }
    return false;
}

void CatRun(Cat *rootcat)
{
    moveCat(rootcat, 0, 0, 2);
}

void moveCat(Cat *rootcat, float x, float y, float z)
{
    Cat *current = rootcat;

    while (current->bud != NULL)
    {
        current->position.x = current->position.x + x;
        current->position.y = current->position.y + y;
        current->position.z = current->position.z + z;
        current = current->bud;
        /* code */
    }
}

Cat *getLastCatPtr(Cat *rootcat)
{
    printf("current");
    Cat *current = rootcat;
    printf("while loop starting");
    while (current->bud != NULL)
    {
        current = current->bud;
    }

    return current;
}

void UpdateCat()
{
}

int CountCats(Cat *rootcat)
{
    // printf("\n start drawing...\n");
    printf("counting started current");
    Cat *current = rootcat;
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

void DrawCat(Cat *rootcat)
{
    printf("DRAWing started current");
    Cat *current = rootcat;
    printf("while loop starting");

    while (current->bud != NULL)
    {
        DrawModel(current->body, current->position, 1.0f, WHITE);

        current = current->bud;
    }
}

void ClearCatsBehindCamera(Cat *rootcat, Camera3D *camera, Gamestate *context)
{

    Cat *current = rootcat;

    while (current->bud != NULL)
    {
        if (current->position.z > camera->position.z)
        {
            deleteCat(rootcat, current);
            int chance_of_point_increase = GetRandomValue(0, 9);
            if (chance_of_point_increase == 1)
            {
                context->points += 1;
                /* code */
            }
        }
        current = current->bud;
    }
}

void deleteCat(Cat *rootcat, Cat *target)
{

    Cat *current = rootcat;

    while (current->bud != NULL)
    {

        if (current->bud == target)
        {
            current->bud = current->bud->bud;
        }

        current = current->bud;
    }
}