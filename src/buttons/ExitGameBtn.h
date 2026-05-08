#ifndef EXIT_GAME_BUTTON
#define EXIT_GAME_BUTTON

#include "FlappyUtils.h"
#include "TextureButton.h"

TextureButton Fn_CreateExitBtn(void)
{
    TextureButton btn = CreateTextureButton();

    Texture backgroundTexture = Fn_GetDefaultTexture();
    TextureEntity backgroundTextureEntity =
        CreateTextureEntity(backgroundTexture);

    btn.Text       = "Exit Game";
    btn.Background = backgroundTextureEntity;

    return btn;
}

#endif