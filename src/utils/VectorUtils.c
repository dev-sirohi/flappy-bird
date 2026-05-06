#include <stdlib.h>

static const int MAX_INITIAL_ARRAY_SIZE = 0;

typedef struct VectorInt
{
    unsigned int *Array;
    unsigned int Size;
} VectorInt;

VectorInt *GetVectorInt(unsigned int size)
{
    VectorInt *vector =
        (VectorInt *)malloc(sizeof(VectorInt));
    vector->Array = calloc(size, sizeof(unsigned int));
    vector->Size  = size;
    return vector;
}
