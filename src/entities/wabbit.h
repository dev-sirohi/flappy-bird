#ifndef ENTITY_WABBIT
#define ENTITY_WABBIT

#include "TextureEntity.h"

TextureEntity Fn_CreateWabbit(void);
void Fn_MakeWabbit(TextureEntity *entity);
static void Fn_MoveWabbit(TextureEntity *entity);
static void Fn_DrawWabbit(TextureEntity *entity);

TextureEntity Fn_CreateWabbit(void)
{
    TextureEntity entity;
    entity.Texture    = LoadTexture("wabbit_alpha.png");
    entity.Position.x = GetScreenWidth() / 2.0f;
    entity.Position.y = GetScreenHeight() / 5.0f;
    entity.Velocity.x = 5.0f;
    entity.Velocity.y = 5.0f;
    entity.Tint       = WHITE;
    entity.Scale      = 2.5f;

    entity.Move = Fn_MoveWabbit;
    entity.Draw = Fn_DrawWabbit;
    return entity;
}

void Fn_MakeWabbit(TextureEntity *entity)
{
    entity->Texture    = LoadTexture("wabbit_alpha.png");
    entity->Position.x = GetScreenWidth() / 2.0f;
    entity->Position.y = GetScreenHeight() / 5.0f;
    entity->Velocity.x = 5.0f;
    entity->Velocity.y = 5.0f;
    entity->Tint       = WHITE;
    entity->Scale      = 2.5f;
}

static void Fn_MoveWabbit(TextureEntity *entity)
{
    if (entity == NULL)
    {
        return;
    }

    if (IsKeyDown(KEY_UP))
    {
        entity->Position.y -= entity->Velocity.y;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        entity->Position.y += entity->Velocity.y;
    }
    if (IsKeyDown(KEY_LEFT))
    {
        entity->Position.x -= entity->Velocity.x;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        entity->Position.x += entity->Velocity.x;
    }
}

static void Fn_DrawWabbit(TextureEntity *entity)
{
    DrawTextureEx(entity->Texture,
                  entity->Position,
                  entity->Rotation,
                  entity->Scale,
                  entity->Tint);
}

#endif