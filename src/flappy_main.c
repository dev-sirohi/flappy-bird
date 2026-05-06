#include "FlappyUtils.h"
#include "Tex.h"
#include "TextureEntity.h"
#include "raylib.h"
#include "resource_dir.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

static Entity ent_wabbit;
static Tex tx_title;

static void Fn_PreInitializeOperations(void);
static void Fn_InitializeEntities(void);
static void Fn_InitializeTexes(void);
static void Fn_CleanUp(void);

static void Fn_Update(void);
static void Fn_Draw(void);

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(Fn_GetWindowWidth(),
               Fn_GetWindowHeight(),
               Fn_GetTitle());
    // ToggleFullscreen();
    SearchAndSetResourceDir("resources");

    Fn_PreInitializeOperations();
    Fn_InitializeEntities();
    Fn_InitializeTexes();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        Fn_Update();
        Fn_Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

static void Fn_PreInitializeOperations(void)
{
    Fn_Entity_InitDefaults(&ent_wabbit);
    Fn_TextEntity_InitDefaults(&tx_title);
}

static void Fn_InitializeEntities(void)
{
    ent_wabbit.Texture    = LoadTexture("wabbit_alpha.png");
    ent_wabbit.Position.x = GetScreenWidth() / 2.0f;
    ent_wabbit.Position.y = GetScreenHeight() / 5.0f;
    ent_wabbit.Velocity.x = 1.5;
    ent_wabbit.Velocity.y = 1.5;
    ent_wabbit.Tint       = WHITE;
    ent_wabbit.Fn_Move    = Fn_MoveWabbit;
    ent_wabbit.Fn_Draw    = Fn_DrawWabbit;
}

static void Fn_InitializeTexes(void)
{
    tx_title.TextFont   = GetFontDefault();
    tx_title.Text       = "Flappy Wabbit2";
    tx_title.Position.x = GetScreenWidth() / 2.0f;
    tx_title.Position.y = GetScreenHeight() / 5.0f;
    tx_title.Tint       = GREEN;
    tx_title.FontSize   = 40.0f;
    tx_title.Fn_DrawPro = Fn_DrawTitlePro;

    Vector2 textSize =
        Fn_TextEntity_MeasureSizeEx(&tx_title);
    tx_title.Origin.x = textSize.x / 2.0f;
    tx_title.Origin.y = textSize.y / 2.0f;
}

static void Fn_CleanUp(void)
{
    ent_wabbit.Fn_CleanUp(&ent_wabbit);
}

static void Fn_Update(void)
{
    ent_wabbit.Fn_Move(&ent_wabbit);
}

static void Fn_Draw(void)
{
    tx_title.Fn_DrawPro(&tx_title);
    ent_wabbit.Fn_Draw(&ent_wabbit);
}
