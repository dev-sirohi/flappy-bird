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
    void *_sceneData; // Always a private struct containing private
                      // members and methods

    Method_Scene_Init Init;
    Method_Scene_Update Update;
    Method_Scene_Draw Draw;
    Method_Scene_CleanUp CleanUp;
};
// Constructor
Scene CreateScene();

#endif
