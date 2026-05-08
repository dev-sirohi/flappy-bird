#include "Scene.h"
#include "Tex.h"
#include "TextureEntity.h"

typedef struct _SceneData _SceneData;
struct _SceneData
{
    TextureEntity _wabbit;
    Tex _gameName;
    Tex _startBtn;
    Tex _exitBtn;
};

static void Fn_TitleScene_Init(Scene *);
static void Fn_TitleScene_Update(Scene *);
static void Fn_TitleScene_Draw(Scene *);
static void Fn_TitleScene_CleanUp(Scene *);

Scene *CreateTitleScene()
{
    Scene scene;
    scene.EntityList = CreateVectorTextureEntity();
    scene.Init       = Fn_TitleScene_Init;
    scene.Update     = Fn_TitleScene_Update;
    scene.Draw       = Fn_TitleScene_Draw;
    scene.CleanUp    = Fn_TitleScene_CleanUp;
    return &scene;
}

static void Fn_TitleScene_Init(Scene *scene)
{
    return;
}
