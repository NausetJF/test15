#include <stdio.h>
#include "raylib.h"
#include "gamestate.h"
#include "color.h"
#include "cat.h"

Camera3D InitCamera()
{
  Camera3D camera;
  camera.fovy = 45.0f;
  camera.position = (Vector3){0.0f, 0.0f, 30.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.projection = CAMERA_PERSPECTIVE;
  return camera;
}

int main(void)
{
  InitWindow(800, 800, "raylib");
  gamestate game = InitGameState();
  printf("\nfirst cat\n");
  cat *rootcat = InitCat();
  printf("\ndone\n");

  Camera3D camera = InitCamera();

  while (!WindowShouldClose())
  {
    TickCat(rootcat);
    int count_of_cats = CountCats(rootcat); 
    char count_str[15];
    sprintf(count_str,"%d",count_of_cats);
    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode3D(camera);
    {

      // DrawText(count_str,20,10,10,WHITE);
      DrawCat(rootcat);
    }
    printf("%d",count_of_cats);
    DrawText(count_str,20,10,10,WHITE);
    EndMode3D();
    DrawFPS(10, 10);
    EndDrawing();
  }
}
