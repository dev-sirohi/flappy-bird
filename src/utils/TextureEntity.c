#include "TextureEntity.h"
#include "FlappyUtils.h"
#include "raylib.h"
#include <stdlib.h>

void Fn_Entity_InitDefaults(Entity *entity)
{
    entity->Texture  = Fn_LoadDefaultTexture();
    entity->Position = (Vector2){0};
    entity->Velocity = (Vector2){0};
    entity->Tint     = (Color){0};
}

void Fn_CleanUpTextureEntity(Entity *entity)
{
    UnloadTexture(entity->Texture);
}

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
    DrawTexture(wabbit->Texture,
                wabbit->Position.x,
                wabbit->Position.y,
                wabbit->Tint);
}
