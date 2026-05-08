#include "FlappyUtils.h"
#include "Scene.h"
#include "Tex.h"
#include "TextureEntity.h"
#include "TitleScene.h"
#include "raylib.h"
#include "resource_dir.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

Scene titleScene;

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(Fn_GetWindowWidth(), Fn_GetWindowHeight(), Fn_GetTitle());
    // ToggleFullscreen();
    SearchAndSetResourceDir("resources");

    titleScene = CreateTitleScene();
    titleScene.Init(&titleScene);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        titleScene.Update(&titleScene);
        titleScene.Draw(&titleScene);

        EndDrawing();
    }

    titleScene.CleanUp(&titleScene);

    CloseWindow();
    return 0;
}

// static void Fn_InitializeTexes(void)
// {
//     tx_title.TextFont   = GetFontDefault();
//     tx_title.Text       = "Flappy Wabbit";
//     tx_title.Position.x = GetScreenWidth() / 2.0f;
//     tx_title.Position.y = GetScreenHeight() / 5.0f;
//     tx_title.Tint       = GREEN;
//     tx_title.FontSize   = 80.0f;
//     tx_title.Spacing    = 10.0f;
//     tx_title.Fn_DrawPro = Fn_DrawTitlePro;

//     Vector2 textSize  = Fn_TextEntity_MeasureSizeEx(&tx_title);
//     tx_title.Origin.x = textSize.x / 2.0f;
//     tx_title.Origin.y = textSize.y / 2.0f;
// }
