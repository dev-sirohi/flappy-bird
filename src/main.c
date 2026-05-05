#include "flappy_utils.h"
#include "raylib.h"
#include "resource_dir.h"
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(get_window_width(), get_window_height(), get_title());
    SearchAndSetResourceDir("resources");

    struct Entity *wabbit = (void *)malloc(sizeof(struct Entity));
    wabbit->texture       = LoadTexture("wabbit_alpha.png");
    wabbit->position.x    = 0;
    wabbit->position.y    = 0;
    wabbit->velocity.x    = 1.5;
    wabbit->velocity.y    = 1.5;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Hello Raylib", 200, 200, 20, WHITE);

        if (IsKeyDown(KEY_RIGHT))
        {
            // TODO
        }
        if (IsKeyDown(KEY_LEFT))
        {
            // TODO
        }
        if (IsKeyDown(KEY_UP))
        {
            // TODO
        }
        if (IsKeyDown(KEY_DOWN))
        {
            // TODO
        }

        DrawTexture(wabbit->texture, wabbit->position.x, wabbit->position.y, WHITE);

        EndDrawing();
    }

    UnloadTexture(wabbit->texture);
    free(wabbit);

    CloseWindow();
    return 0;
}
