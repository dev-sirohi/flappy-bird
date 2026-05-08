#ifndef TEXTURE_ENTITY
#define TEXTURE_ENTITY

#include "raylib.h"
#include <stddef.h>

typedef struct TextureEntity TextureEntity;
typedef void (*Method_TextureEntity_Update)(TextureEntity *);
typedef void (*Method_TextureEntity_Draw)(TextureEntity *);
typedef void (*Method_TextureEntity_CleanUp)(TextureEntity *);

struct TextureEntity
{
    Texture Texture;
    Vector2 Position;
    float Rotation;
    float Scale;
    Color Tint;

    Vector2 Velocity;

    Method_TextureEntity_Update Update;
    Method_TextureEntity_Draw Draw;
    Method_TextureEntity_CleanUp CleanUp;
};
// Constructor
TextureEntity CreateTextureEntity(Texture texture);

typedef struct VectorTextureEntity VectorTextureEntity;
typedef void (*Method_VectorTextureEntity_Push_Back)(VectorTextureEntity *,
                                                     TextureEntity *value);
typedef void (*Method_VectorTextureEntity_Free)(VectorTextureEntity *);
typedef void (*Method_VectorTextureEntity_Clear)(VectorTextureEntity *);
typedef void (*Method_VectorTextureEntity_RemoveAt)(VectorTextureEntity *,
                                                    size_t index);
typedef TextureEntity (*Method_VectorTextureEntity_LookAt)(
    VectorTextureEntity *, size_t index);

struct VectorTextureEntity
{
    TextureEntity **Array;
    size_t Size;
    size_t Count;
    bool Ok;

    Method_VectorTextureEntity_Push_Back Push_Back;
    Method_VectorTextureEntity_Free Free;
    Method_VectorTextureEntity_Clear Clear;
    Method_VectorTextureEntity_RemoveAt RemoveAt;
    Method_VectorTextureEntity_LookAt LookAt;
};
// Constructor
VectorTextureEntity CreateVectorTextureEntity(void);

#endif
