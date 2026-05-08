#include "ExitGameBtn.h"
#include "FlappyUtils.h"
#include "Scene.h"
#include "StartGameBtn.h"
#include "Tex.h"
#include "TextureButton.h"
#include "TextureEntity.h"
#include "Wabbit.h"
#include "stdlib.h"

typedef struct _TitleSceneData _TitleSceneData;
struct _TitleSceneData
{
    TextureEntity _wabbit;
    Tex _gameName;
    TextureButton _startBtn;
    TextureButton _exitBtn;
};

static void Fn_TitleScene_Init(Scene *);
static void Fn_TitleScene_Update(Scene *);
static void Fn_TitleScene_Draw(Scene *);
static void Fn_TitleScene_CleanUp(Scene *);

Scene CreateTitleScene()
{
    Scene scene;
    scene.Init    = Fn_TitleScene_Init;
    scene.Update  = Fn_TitleScene_Update;
    scene.Draw    = Fn_TitleScene_Draw;
    scene.CleanUp = Fn_TitleScene_CleanUp;
    return scene;
}

// Set properties through parameterized function for consistency
static void Fn_TitleScene_SetSceneData(_TitleSceneData *sceneData,
                                       TextureEntity wabbit,
                                       Tex gameName,
                                       TextureButton startBtn,
                                       TextureButton exitBtn

)
{
    sceneData->_wabbit   = wabbit;
    sceneData->_gameName = gameName;
    sceneData->_startBtn = startBtn;
    sceneData->_exitBtn  = exitBtn;
}

static void Fn_TitleScene_Init(Scene *scene)
{
    _TitleSceneData *sceneData = malloc(sizeof(_TitleSceneData));

    // Create Wabbit texture
    TextureEntity wabbit = CreateWabbit();
    wabbit.Position.x    = 10.0f;
    wabbit.Position.y    = 10.0f;
    wabbit.Scale         = 1.0f;

    // Create Game Title tex
    Tex gameName        = CreateTex(Fn_GetTitle());
    gameName.FontSize   = 40.0f;
    gameName.Position.x = GetScreenWidth() / 2.0f;
    gameName.Position.y = GetScreenHeight() / 2.0f;
    gameName.Origin.x   = gameName.MeasureSize(&gameName).x - 10.0f;
    gameName.Spacing    = 10.0f;
    gameName.Tint       = GREEN;

    // Create Start & Exit Buttons
    TextureButton startBtn = Fn_CreateStartBtn();
    TextureButton exitBtn  = Fn_CreateExitBtn();

    Fn_TitleScene_SetSceneData(sceneData,
                               wabbit,
                               gameName,
                               startBtn,
                               exitBtn);

    scene->_sceneData = sceneData;
}

static void Fn_TitleScene_Update(Scene *scene)
{
    _TitleSceneData *sceneData = (_TitleSceneData *)scene->_sceneData;
    sceneData->_wabbit.Update(&sceneData->_wabbit);
    sceneData->_gameName.Update(&sceneData->_gameName);
    sceneData->_startBtn.OnClick(&sceneData->_startBtn);
    sceneData->_exitBtn.OnClick(&sceneData->_exitBtn);
}

static void Fn_TitleScene_Draw(Scene *scene)
{
    _TitleSceneData *sceneData = (_TitleSceneData *)scene->_sceneData;
    sceneData->_wabbit.Draw(&sceneData->_wabbit);
    sceneData->_gameName.Draw(&sceneData->_gameName);
    sceneData->_startBtn.Draw(&sceneData->_startBtn);
    sceneData->_exitBtn.Draw(&sceneData->_exitBtn);
}

static void Fn_TitleScene_CleanUp(Scene *)
{
}