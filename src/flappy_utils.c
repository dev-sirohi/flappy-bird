#include "flappy_utils.h"
#include <stdlib.h>

/* Core Util Functions */
int Fn_GetWindowHeight(void)
{
    return 450;
}
int Fn_GetWindowWidth(void)
{
    return 800;
}
char *Fn_GetTitle(void)
{
    return "Flappy";
}

/* Entity Movement Functions */
void Fn_MoveWabbit(Entity *wabbit)
{
    if (wabbit == NULL)
    {
        return;
    }

    if (IsKeyDown(KEY_UP))
    {
        wabbit->Position.y -= wabbit->Velocity.y;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        wabbit->Position.y += wabbit->Velocity.y;
    }
    if (IsKeyDown(KEY_LEFT))
    {
        wabbit->Position.x -= wabbit->Velocity.x;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        wabbit->Position.x += wabbit->Velocity.x;
    }
}

void Fn_DrawWabbit(Entity *wabbit)
{
    DrawTexture(wabbit->Texture, wabbit->Position.x, wabbit->Position.y, wabbit->Color);
}

void Fn_DrawTitle(Tex *title)
{
    DrawText(title->Text, title->Position.x, title->Position.y, title->FontSize, title->Color);
}