#include <stdio.h>
#include "raylib.h"
#include "gamestate.h"
#include "color.h"
#include "cat.h"
#include "stage.h"
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
  


  printf("\nmainstage init.\n");
  stage *mainstage_ptr = InitStage();  


  SetTargetFPS(60);
  Camera3D camera = InitCamera();
  while (!WindowShouldClose())
  {
    UpdateCamera(&camera,CAMERA_ORBITAL);
    GameTick(rootcat, &game);
    int count_of_cats = CountCats(rootcat);
    char count_str[15];
    sprintf(count_str, "%d", count_of_cats);
    BeginDrawing();
    {
      ClearBackground(BLACK);
      BeginMode3D(camera);
      {
        DrawStage(mainstage_ptr);
        DrawCat(rootcat);
      }
      printf("\n\n%d\n\n", count_of_cats);
      EndMode3D();
      DrawText(count_str, 10, 40, 40, WHITE);
      DrawFPS(10, 10);
    }
    EndDrawing();
  }
}
