#ifndef TEXT_ENTITY
#define TEXT_ENTITY

#include "raylib.h"

typedef struct TextEntity Tex;
typedef void (*Fn_TextEntity_Move)(Tex *);
typedef void (*Fn_TextEntity_Draw)(Tex *);
typedef void (*Fn_TextEntity_DrawEx)(Tex *);
typedef void (*Fn_TextEntity_DrawPro)(Tex *);

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

    Fn_TextEntity_Move Fn_Move;
    Fn_TextEntity_Draw Fn_Draw;
    Fn_TextEntity_DrawEx Fn_DrawEx;
    Fn_TextEntity_DrawPro Fn_DrawPro;
};

void Fn_TextEntity_InitDefaults(Tex *tex);
Vector2 Fn_TextEntity_MeasureSizeEx(Tex *tex);

void Fn_DrawTitlePro(Tex *title);

#endif
