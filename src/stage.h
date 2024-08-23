#ifndef STAGE_H
#define STAGE_H
#include "raylib.h"

struct stage
{
    Vector3 pos;
    Model meshes[10];
    Vector3 mesh_pos[10];
    bool is_used[10];

    /* data */
};

typedef struct stage stage;

stage *InitStage();

void DrawStage(stage *stage_ptr);

void StageTick(stage *stage_ptr);


#endif // !STAGE_H
#define STAGE_H