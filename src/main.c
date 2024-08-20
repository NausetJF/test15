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
  

  float movement_speed = 0.5f;
  Mesh box = GenMeshCube(20.0f,20.0f,50.0f);
  BoundingBox bounding_box = GetMeshBoundingBox(box);

  while (!WindowShouldClose())
  {
    if (IsKeyDown(KEY_R))
    {
      UpdateCamera(&camera,CAMERA_ORBITAL);

      /* code */
    }
    
    bool isbound = CheckCollisionBoxSphere(bounding_box,camera.position,1.0f);

    CatTick(rootcat, &game);
    int count_of_cats = CountCats(rootcat);
    char count_str[15];
    sprintf(count_str, "%d", count_of_cats);
    printf("\n\nis bound: %d\n",isbound);
    if (IsKeyDown(KEY_D) && isbound)
    {
      camera.position.x += movement_speed;
      camera.target.x += movement_speed;
   
        /* code */
    }
    if (IsKeyDown(KEY_A) && isbound)
    {
      camera.position.x -= movement_speed;
      camera.target.x -= movement_speed;
      
    }
    
    if (IsKeyDown(KEY_W) && isbound)
    {
      camera.position.y += movement_speed;
      camera.target.y += movement_speed;
      
    }
    
    
    if (IsKeyDown(KEY_S) && isbound)
    {
      camera.position.y -= movement_speed;
      camera.target.y -= movement_speed;
     
    }
      // camera.target.y -= 1;
    
      // camera.position.y -= 1;
    BeginDrawing();
    {
      ClearBackground(BLACK);
      BeginMode3D(camera);
      {
        DrawModelWires(LoadModelFromMesh(box),(Vector3){0,0,0},1.0f,WHITE);
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
