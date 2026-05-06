#ifndef FLAPPY_UTILS
#define FLAPPY_UTILS

#include "flappy_enums.h"
#include "raylib.h"

/* Core Util Functions */
int Fn_GetWindowHeight(void);
int Fn_GetWindowWidth(void);
char *Fn_GetTitle(void);

/* Entity Definitions */
typedef struct TextureEntity Entity;
typedef void (*Fn_Entity_Move)(Entity *);
typedef void (*Fn_Entity_Draw)(Entity *);

typedef struct TextEntity Tex;
typedef void (*Fn_TextEntity_Move)(Tex *);
typedef void (*Fn_TextEntity_Draw)(Tex *);

struct TextureEntity
{
    Texture Texture;
    Vector2 Position;
    Vector2 Velocity;
    Color Color;

    Fn_Entity_Move Fn_Move;
    Fn_Entity_Draw Fn_Draw;
};
struct TextEntity
{
    char *Text;
    Vector2 Position;
    Vector2 Velocity;
    Color Color;
    int FontSize;

    Fn_TextEntity_Move Fn_Move;
    Fn_TextEntity_Draw Fn_Draw;
};

/* Entity Movement Functions */
void Fn_MoveWabbit(Entity *wabbit);
void Fn_DrawWabbit(Entity *wabbit);

void Fn_DrawTitle(Tex *title);

#endif
