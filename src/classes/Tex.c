#include "Tex.h"
#include "raylib.h"

Vector2 Fn_TextEntity_MeasureSize(Tex *tex);
static void Fn_TextEntity_Draw(Tex *title);
static void Fn_TextEntity_Update(Tex *title);

Tex CreateTex(char *text)
{
    Tex tex;
    tex.TextFont = GetFontDefault();
    tex.Text     = text;
    tex.Position = (Vector2){0};
    tex.Origin   = (Vector2){0};
    tex.Rotation = 0.0f;
    tex.FontSize = 0.0f;
    tex.Spacing  = 0.0f;
    tex.Velocity = (Vector2){0};
    tex.Tint     = (Color){0};

    tex.Update      = Fn_TextEntity_Update;
    tex.Draw        = Fn_TextEntity_Draw;
    tex.MeasureSize = Fn_TextEntity_MeasureSize;

    return tex;
}

Vector2 Fn_TextEntity_MeasureSize(Tex *tex)
{
    return MeasureTextEx(tex->TextFont,
                         tex->Text,
                         tex->FontSize,
                         tex->Spacing);
}

static void Fn_TextEntity_Draw(Tex *title)
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

static void Fn_TextEntity_Update(Tex *title)
{
}