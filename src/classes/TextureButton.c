#include "TextureButton.h"

static void Fn_TextureButton_OnClick(TextureButton *button);
static void Fn_TextureButton_Draw(TextureButton *button);

TextureButton CreateTextureButton(void)
{
    TextureButton button;
    button.OnClick = Fn_TextureButton_OnClick;
    button.Draw    = Fn_TextureButton_Draw;
    return button;
}

static void Fn_TextureButton_OnClick(TextureButton *button)
{
}

static void Fn_TextureButton_Draw(TextureButton *button)
{
    button->Background.Draw(&button->Background);
}