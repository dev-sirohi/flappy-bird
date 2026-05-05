#ifndef FLAPPY_UTILS
#define FLAPPY_UTILS

#include "raylib.h"

int get_window_height(void);
int get_window_width(void);
char *get_title(void);

struct Entity
{
    Texture texture;
    Vector2 position;
    Vector2 velocity;
};

#endif
