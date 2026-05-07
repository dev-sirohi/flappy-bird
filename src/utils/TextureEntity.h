#ifndef TEXTURE_ENTITY
#define TEXTURE_ENTITY

#include "raylib.h"

typedef struct TextureEntity Entity;
typedef void (*Fn_Entity_Init)(Entity *);
typedef void (*Fn_Entity_Move)(Entity *);
typedef void (*Fn_Entity_Draw)(Entity *);
typedef void (*Fn_Entity_CleanUp)(Entity *);

struct TextureEntity
{
    Texture Texture;
    Vector2 Position;
    float Rotation;
    float Scale;
    Color Tint;

    Vector2 Velocity;

    Fn_Entity_Move Fn_Move;
    Fn_Entity_Draw Fn_Draw;
    Fn_Entity_CleanUp Fn_CleanUp;
};

void Fn_Entity_InitDefaults(Entity *entity);
void Fn_CleanUpTextureEntity(Entity *entity);

void Fn_MoveWabbit(Entity *wabbit);
void Fn_DrawWabbit(Entity *wabbit);

#endif
