#include "FlappyUtils.h"
#include <stdlib.h>

/* Core Util Functions */
int Fn_GetWindowHeight(void)
{
    return 450;
}
int Fn_GetWindowWidth(void)
{
    return 800;
}
char *Fn_GetTitle(void)
{
    return "Flappy Wabbit";
}
Texture Fn_GetDefaultTexture()
{
    return (Texture){0}; // TODO
}
