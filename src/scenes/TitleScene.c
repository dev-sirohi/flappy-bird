#include "FlappyUtils.h"
#include "SceneUtils.h"
#include "Tex.h"
#include "TextureEntity.h"

static void Fn_TitleScene_Init(Scene *);
static void Fn_TitleScene_Update(Scene *);
static void Fn_TitleScene_Draw(Scene *);
static void Fn_TitleScene_CleanUp(Scene *);

Scene Fn_GetTitleScene()
{
    Scene scene;
    scene.EntityList = CreateVectorTextureEntity();
    scene.Init       = Fn_TitleScene_Init;
    scene.Update     = Fn_TitleScene_Update;
    scene.Draw       = Fn_TitleScene_Draw;
    scene.CleanUp    = Fn_TitleScene_CleanUp;
}

static void Fn_TitleScene_Init(Scene *scene)
{
    return;
}