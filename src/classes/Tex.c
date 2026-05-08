#include "Tex.h"
#include "raylib.h"

void Fn_TextEntity_InitDefaults(Tex *tex)
{
    tex->TextFont = GetFontDefault();
    tex->Text     = "Default";
    tex->Position = (Vector2){0};
    tex->Origin   = (Vector2){0};
    tex->Rotation = 0.0f;
    tex->FontSize = 0.0f;
    tex->Spacing  = 0.0f;
    tex->Velocity = (Vector2){0};
    tex->Tint     = (Color){0};
}

Vector2 Fn_TextEntity_MeasureSizeEx(Tex *tex)
{
    return MeasureTextEx(tex->TextFont,
                         tex->Text,
                         tex->FontSize,
                         tex->Spacing);
}

void Fn_DrawTitlePro(Tex *title)
{
    DrawTextPro(title->TextFont,
                title->Text,
                title->Position,
                title->Origin,
                title->Rotation,
                title->FontSize,
                title->Spacing,
                title->Tint);
}
