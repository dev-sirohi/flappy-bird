#ifndef SCENE_UTILS
#define SCENE_UTILS

#include "TextureEntity.h"

typedef struct Scene Scene;
typedef void (*Method_Scene_Init)(Scene *);
typedef void (*Method_Scene_Update)(Scene *);
typedef void (*Method_Scene_Draw)(Scene *);
typedef void (*Method_Scene_CleanUp)(Scene *);

struct Scene
{
    VectorTextureEntity EntityList;

    Method_Scene_Init Init;
    Method_Scene_Update Update;
    Method_Scene_Draw Draw;
    Method_Scene_CleanUp CleanUp;
};

Scene CreateScene()
{
    Scene scene;
    scene.EntityList = CreateVectorTextureEntity();
    return scene;
}

#endif
