#include "stage.h"
#include "gamestate.h"
#include <stdlib.h>
#include <stdio.h>
#include "rlgl.h"
stage* InitStage()
{
    stage *newstage_ptr = (stage*)malloc(sizeof(stage));
    newstage_ptr->pos = (Vector3){0,0,0};
    for (int i = 0; i < 9; ++i) { newstage_ptr->is_used[i] = false;}
    Mesh floor = GenMeshPlane(ALLEY_X,ALLEY_X*4,10,10);
    Model floorModel = LoadModelFromMesh(floor);
    // Image concrete = GenImagePerlinNoise(10,10,0,0,1.0f);
    // Texture2D concrete_tex = LoadTextureFromImage(concrete);
    newstage_ptr->mesh_pos[0] = (Vector3){0.0f,-12.0f,-0.0f};
    // floorModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = concrete_tex;
    // UnloadImage(concrete);
    // UnloadMesh(floor);
    newstage_ptr->meshes[0] = floorModel;
    newstage_ptr->is_used[0] = true;
    
    // // Image concrete = GenImagePerlinNoise(10,10,0,0,1.0f);
    // // Texture2D concrete_tex = LoadTextureFromImage(concrete);
    // newstage_ptr->mesh_pos[0] = (Vector3){0.0f,-20.0f,-10.0f};
    // // floorModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = concrete_tex;
    // // UnloadImage(concrete);
    // // UnloadMesh(floor);
    // newstage_ptr->meshes[1] = floorModel;
    // newstage_ptr->is_used[1] = true;


    return newstage_ptr;
}

void DrawStage(stage *stage_ptr)
{
    stage stage_r = *stage_ptr;
    DrawModel(stage_r.meshes[0],stage_r.mesh_pos[0],1.0f,GRAY);
    // for (int i = 0; i < 1; i++)
    // {
    //     if (stage_ptr->is_used[i] == true)
    //     {
    //         printf("should be drawing the background mesh");
    //         DrawModel(stage_ptr->meshes[i],stage_ptr->mesh_pos[i],1.0f,WHITE);
    //     }
        
    // }
    
}

void StageTick(stage *stage_ptr)
{
}
