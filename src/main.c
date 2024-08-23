#include <stdio.h>
#include "raylib.h"
#include "gamestate.h"
#include "color.h"
#include "cat.h"
#include "stage.h"
#include "ui.h"
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
  Gamestate game = InitGameState();
  printf("\nfirst cat\n");
  Cat *rootcat = InitCat();
  printf("\ndone\n");

  printf("\nmainstage init.\n");
  stage *mainstage_ptr = InitStage();

  SetTargetFPS(60);
  Camera3D camera = InitCamera();

  float movement_speed = 0.5f;
  Mesh box = GenMeshCube(20.0f, 20.0f, 100.0f);
  BoundingBox bounding_box = GetMeshBoundingBox(box);

  Vector3 oldpos = (Vector3){0.0f, 0.0f, 30.0f};
  Vector3 oldtar = (Vector3){0.0f, 0.0f, 0.0f};
  while (!WindowShouldClose())
  {
    if (IsKeyDown(KEY_R) || game.running == false)
    {
      UpdateCamera(&camera, CAMERA_ORBITAL);
    }

    bool isbound = CheckCollisionBoxSphere(bounding_box, camera.position, 1.0f);

    int count_of_cats = CountCats(rootcat);
    char count_str[15];
    sprintf(count_str, "%d", count_of_cats);
    printf("\n\nis bound: %d\n", isbound);
    if (isbound)
    {
      oldpos = camera.position;
      oldtar = camera.target;
    }
    if (IsKeyDown(KEY_D) && isbound && game.running)
    {
      camera.position.x += movement_speed;
      camera.target.x += movement_speed;

      if (!isbound)
      {
        camera.position.x -= movement_speed * 2;
        camera.target.x -= movement_speed * 2;
      }
      /* code */
    }
    if (IsKeyDown(KEY_A) && isbound && game.running)
    {
      camera.position.x -= movement_speed;
      camera.target.x -= movement_speed;

      if (!isbound)
      {
        camera.position.x += movement_speed * 2;
        camera.target.x += movement_speed * 2;
      }
    }

    if (IsKeyDown(KEY_W) && isbound && game.running)
    {
      camera.position.y += movement_speed;
      camera.target.y += movement_speed;

      if (!isbound)
      {
        camera.position.y -= movement_speed * 2;
        camera.target.y -= movement_speed * 2;
      }
    }

    if (IsKeyDown(KEY_S) && isbound && game.running)
    {
      camera.position.y -= movement_speed;
      camera.target.y -= movement_speed;
      if (!isbound)
      {
        camera.position.y += movement_speed * 2;
        camera.target.y += movement_speed * 2;
      }
    }
    if (!isbound)
      camera.position = oldpos;
    if (!isbound)
      camera.target = oldtar;

    BeginDrawing();
    {
      ClearBackground(BLACK);
      BeginMode3D(camera);
      {

        CatTick(rootcat, &game, &camera);
        DrawModelWires(LoadModelFromMesh(box), (Vector3){0, 0, 0}, 1.0f, RED);
        DrawStage(mainstage_ptr);
        DrawCat(rootcat);
      }
      printf("\n\n%d\n\n", count_of_cats);
      EndMode3D();
      DrawText(count_str, 40, GetScreenHeight()-40, 40, WHITE);
      DrawFPS(10, 10);
      RenderUI(&game);
    }

    EndDrawing();
    if (IsKeyDown(KEY_Q))
    {
      CloseWindow();
    }
  }
}
