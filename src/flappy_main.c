#include "flappy_utils.h"
#include "raylib.h"
#include "resource_dir.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

static Entity t_wabbit;
static Tex tx_title;

static void Fn_InitializeEntities(void);
static void Fn_InitializeTexes(void);
static void Fn_CleanUp(void);

static void Fn_Update(void);
static void Fn_Draw(void);

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(Fn_GetWindowWidth(), Fn_GetWindowHeight(), Fn_GetTitle());
    SearchAndSetResourceDir("resources");

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

static void Fn_InitializeEntities(void)
{
    t_wabbit.Texture    = LoadTexture("wabbit_alpha.png");
    t_wabbit.Position.x = 0;
    t_wabbit.Position.y = 0;
    t_wabbit.Velocity.x = 1.5;
    t_wabbit.Velocity.y = 1.5;
    t_wabbit.Color      = WHITE;
    t_wabbit.Fn_Move    = Fn_MoveWabbit;
    t_wabbit.Fn_Draw    = Fn_DrawWabbit;
}

static void Fn_InitializeTexes(void)
{
    tx_title.Text       = "Flappy";
    tx_title.Position.x = 100;
    tx_title.Position.y = 100;
    tx_title.Color      = WHITE;
    tx_title.FontSize   = 10;
    tx_title.Fn_Draw    = Fn_DrawTitle;
}

static void Fn_CleanUp(void)
{
    UnloadTexture(t_wabbit.Texture);
}

static void Fn_Update(void)
{
    t_wabbit.Fn_Move(&t_wabbit);
}

static void Fn_Draw(void)
{
    tx_title.Fn_Draw(&tx_title);
    t_wabbit.Fn_Draw(&t_wabbit);
}