#ifndef TEXT_ENTITY
#define TEXT_ENTITY

#include "raylib.h"

typedef struct TextEntity Tex;
typedef void (*Method_TextEntity_Update)(Tex *);
typedef void (*Method_TextEntity_Draw)(Tex *);
typedef Vector2 (*Method_TextEntity_MeasureSize)(Tex *);

struct TextEntity
{
    Font TextFont;
    char *Text;
    Vector2 Position;
    Vector2 Origin;
    Color Tint;
    float FontSize;
    float Rotation;
    float Spacing;

    Vector2 Velocity;

    Method_TextEntity_Update Update;
    Method_TextEntity_Draw Draw;
    Method_TextEntity_MeasureSize MeasureSize;
};
// Constructor
Tex CreateTex(char *text);

#endif
