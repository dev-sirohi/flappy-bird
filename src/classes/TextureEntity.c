#include "TextureEntity.h"
#include "FlappyUtils.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

/* Texture Entity */
static void Fn_TextureEntity_Update(TextureEntity *entity);
static void Fn_TextureEntity_Draw(TextureEntity *entity);
static void Fn_TextureEntity_CleanUp(TextureEntity *entity);

TextureEntity CreateTextureEntity(Texture texture)
{
    TextureEntity entity;
    entity.Texture  = Fn_GetDefaultTexture();
    entity.Position = (Vector2){0};
    entity.Velocity = (Vector2){0};
    entity.Rotation = 0.0f;
    entity.Scale    = 1.0f;
    entity.Tint     = (Color){0};
    entity.CleanUp  = Fn_TextureEntity_CleanUp;
    entity.Update   = Fn_TextureEntity_Update;
    entity.Draw     = Fn_TextureEntity_Draw;
    return entity;
}

static void Fn_TextureEntity_Update(TextureEntity *entity)
{
}
static void Fn_TextureEntity_Draw(TextureEntity *entity)
{
}

static void Fn_TextureEntity_CleanUp(TextureEntity *entity)
{
    UnloadTexture(entity->Texture);
}

/* VectorTextureEntity */

#define INITIAL_VECTOR_CAPACITY 1

static void Fn_VectorTextureEntity_Push_Back(VectorTextureEntity *vector,
                                             TextureEntity *value)
{
    if (!vector->Ok)
    {
        return;
    }
    if (vector->Count == vector->Size)
    {
        TextureEntity *temp = (TextureEntity *)realloc(
            vector->Array,
            (vector->Size * 2) * sizeof(TextureEntity *));
        if (temp == NULL)
        {
            fprintf(stderr,
                    "%s:%d: Unable to resize vector\n",
                    __FILE__,
                    __LINE__);

            vector->Ok = false;

            return;
        }

        vector->Array = &temp;
        vector->Size *= 2;
    }
    vector->Array[vector->Count++] = value;
}

static void Fn_VectorTextureEntity_Free(VectorTextureEntity *vector)
{
    free(vector->Array);
    vector->Array = NULL;
}

static void Fn_VectorTextureEntity_Clear(VectorTextureEntity *vector)
{
    if (!vector->Ok)
    {
        return;
    }
    free(vector->Array);
    vector->Array = NULL;
    TextureEntity *temp =
        (TextureEntity *)realloc(vector->Array, INITIAL_VECTOR_CAPACITY);
    if (temp == NULL)
    {
        fprintf(stderr,
                "%s:%d: Unable to resize vector\n",
                __FILE__,
                __LINE__);
        vector->Ok = false;

        return;
    }
    vector->Array = &temp;
    vector->Size  = 0;
    vector->Count = 0;
    vector->Ok    = true;
}

static void Fn_VectorTextureEntity_RemoveAt(VectorTextureEntity *vector,
                                            size_t index)
{
    if (!vector->Ok)
    {
        return;
    }
}

static TextureEntity
Fn_VectorTextureEntity_LookAt(VectorTextureEntity *vector, size_t index)
{
    TextureEntity textureEntity;
    if (index >= vector->Count)
    {
        fprintf(stderr,
                "%s:%d: Trying to access invalid memory in "
                "vector\n",
                __FILE__,
                __LINE__);

        exit(EXIT_FAILURE);
    }
    textureEntity = *vector->Array[index];
    return textureEntity;
}

VectorTextureEntity CreateVectorTextureEntity(void)
{
    VectorTextureEntity vector;
    vector.Ok    = true;
    vector.Size  = INITIAL_VECTOR_CAPACITY;
    vector.Array = calloc(vector.Size, sizeof(TextureEntity *));
    if (vector.Array == NULL)
    {
        vector.Ok   = false;
        vector.Size = 0;
    }
    vector.Count = 0;

    vector.Push_Back = Fn_VectorTextureEntity_Push_Back;
    vector.Free      = Fn_VectorTextureEntity_Free;
    vector.Clear     = Fn_VectorTextureEntity_Clear;
    vector.RemoveAt  = Fn_VectorTextureEntity_RemoveAt;
    vector.LookAt    = Fn_VectorTextureEntity_LookAt;

    return vector;
}