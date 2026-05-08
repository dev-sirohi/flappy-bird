#ifndef START_GAME_BUTTON
#define START_GAME_BUTTON

#include "FlappyUtils.h"
#include "TextureButton.h"

TextureButton Fn_CreateStartBtn(void)
{
    TextureButton btn = CreateTextureButton();

    Texture backgroundTexture = Fn_GetDefaultTexture();
    TextureEntity backgroundTextureEntity =
        CreateTextureEntity(backgroundTexture);

    btn.Text       = "Start Game";
    btn.Background = backgroundTextureEntity;

    return btn;
}

#endif