#include "Wabbit.h"
#include "TextureEntity.h"

static void Fn_UpdateWabbit(TextureEntity *entity);
static void Fn_DrawWabbit(TextureEntity *entity);

TextureEntity CreateWabbit(void)
{
    TextureEntity entity;
    MakeWabbit(&entity);
    return entity;
}

void MakeWabbit(TextureEntity *entity)
{
    entity->Texture    = LoadTexture("wabbit_alpha.png");
    entity->Position.x = GetScreenWidth() / 2.0f;
    entity->Position.y = GetScreenHeight() / 5.0f;
    entity->Velocity.x = 5.0f;
    entity->Velocity.y = 5.0f;
    entity->Tint       = WHITE;
    entity->Scale      = 1.0f;

    entity->Update = Fn_UpdateWabbit;
    entity->Draw   = Fn_DrawWabbit;
}

static void Fn_UpdateWabbit(TextureEntity *entity)
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