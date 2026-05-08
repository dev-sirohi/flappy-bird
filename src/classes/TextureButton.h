#ifndef CLASS_TEXTURE_BUTTON
#define CLASS_TEXTURE_BUTTON

#include "TextureEntity.h"

typedef struct TextureButton TextureButton;
typedef void (*Method_TextureButton_OnClick)(TextureButton *);
typedef void (*Method_TextureButton_Draw)(TextureButton *);

struct TextureButton
{
    char *Text;
    TextureEntity Background;

    Method_TextureButton_OnClick OnClick;
    Method_TextureButton_Draw Draw;
};
// Constructor
TextureButton CreateTextureButton(void);

#endif
