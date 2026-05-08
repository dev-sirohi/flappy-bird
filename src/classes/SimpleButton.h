#ifndef CLASS_SIMPLE_BUTTON
#define CLASS_SIMPLE_BUTTON

typedef struct SimpleButton SimpleButton;
struct SimpleButton
{
    char *Text;
};
// Constructor
SimpleButton CreateSimpleButton(void);

#endif
