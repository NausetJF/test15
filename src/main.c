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
  
  cat rootcat = InitCat();

  Camera3D camera = InitCamera();

  while (!WindowShouldClose())
  {
    TickCat(&rootcat);    
    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode3D(camera);
    {
      DrawCat(&rootcat);
    }
    EndMode3D();
    DrawFPS(10, 10);
    EndDrawing();
  }
}
