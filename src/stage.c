#include "stage.h"
#include "gamestate.h"
#include <stdlib.h>
stage* InitStage()
{
    stage *newstage_ptr = (stage*)malloc(sizeof(stage));
    newstage_ptr->pos = (Vector3){0,0,0};

    Mesh floor = GenMeshPlane(ALLEY_X,ALLEY_X*5,10,10);
    Model floorModel = LoadModelFromMesh(floor);
    Image concrete = GenImagePerlinNoise(10,10,0,0,1.0f);
    Texture2D concrete_tex = LoadTextureFromImage(concrete);
    newstage_ptr->mesh_pos[0] = (Vector3){-1.0f,-1.0f,-1.0f};
    floorModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = concrete_tex;
    UnloadImage(concrete);
    UnloadMesh(floor);
    newstage_ptr->meshes[0] = floorModel;
    newstage_ptr->is_used[0] = true;


    return newstage_ptr;
}

void DrawStage(stage *stage_ptr)
{

    for (int i = 0; i < 10; i++)
    {
        if (stage_ptr->is_used[i] == true)
        {
            DrawModel(stage_ptr->meshes[i],stage_ptr->mesh_pos[i],1.0f,WHITE);
        }
        
    }
    
}

void StageTick(stage *stage_ptr)
{
}
