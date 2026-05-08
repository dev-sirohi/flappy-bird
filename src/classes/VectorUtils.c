// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct VectorInt VectorInt;
// typedef void (*Fn_VectorInt_Push_Back)(VectorInt *,
//                                        int value);
// typedef void (*Fn_VectorInt_Free)(VectorInt *);
// typedef void (*Fn_VectorInt_Clear)(VectorInt *);
// typedef void (*Fn_VectorInt_RemoveAt)(VectorInt *,
//                                       size_t index);
// typedef void (*Fn_VectorInt_LookAt)(VectorInt *,
//                                     size_t index);

// struct VectorInt
// {
//     int *Array;
//     size_t Size;
//     size_t Count;
//     bool Ok;

//     Fn_VectorInt_Push_Back Push_Back;
//     Fn_VectorInt_Free Free;
//     Fn_VectorInt_Clear Clear;
//     Fn_VectorInt_RemoveAt RemoveAt;
//     Fn_VectorInt_LookAt LookAt;
// };

// void VectorInt_Push_Back(VectorInt *vector, int value)
// {
//     if (!vector->Ok)
//     {
//         return;
//     }
//     if (vector->Count == vector->Size)
//     {
//         int *temp =
//             realloc(vector->Array,
//                     (vector->Size * 2) * sizeof(int));
//         if (temp == NULL)
//         {
//             fprintf(stderr,
//                     "%s:%d: Unable to resize vector\n",
//                     __FILE__,
//                     __LINE__);

//             vector->Ok = false;

//             return;
//         }

//         vector->Array = temp;
//         vector->Size *= 2;
//     }
//     vector->Array[vector->Count++] = value;
// }

// void VectorInt_Free(VectorInt *vector)
// {
//     free(vector->Array);
//     free(vector);
// }

// void VectorInt_Clear(VectorInt *vector)
// {
//     if (!vector->Ok)
//     {
//         return;
//     }
//     free(vector->Array);
//     int *temp = realloc(vector->Array, 0);
//     if (temp == NULL)
//     {
//         fprintf(stderr,
//                 "%s:%d: Unable to resize vector\n",
//                 __FILE__,
//                 __LINE__);
//         vector->Ok = false;

//         return;
//     }
//     vector->Array = temp;
//     vector->Size  = 0;
//     vector->Count = 0;
//     vector->Ok    = true;
// }

// void VectorInt_RemoveAt(VectorInt *vector, size_t index)
// {
//     if (!vector->Ok)
//     {
//         return;
//     }
// }

// int VectorInt_LookAt(VectorInt *vector, size_t index)
// {
//     if (index >= vector->Count)
//     {
//         fprintf(stderr,
//                 "%s:%d: Trying to access invalid memory in "
//                 "vector\n",
//                 __FILE__,
//                 __LINE__);

//         return 0;
//     }
//     return vector->Array[index];
// }

// VectorInt GetVectorInt(size_t size)
// {
//     VectorInt vector;
//     vector.Ok    = true;
//     vector.Size  = size;
//     vector.Array = calloc(size, sizeof(int));
//     if (vector.Array == NULL)
//     {
//         vector.Ok   = false;
//         vector.Size = 0;
//     }
//     vector.Count = 0;

//     vector.Push_Back = VectorInt_Push_Back;
//     vector.Free      = VectorInt_Free;
//     vector.Clear     = VectorInt_Clear;
//     vector.RemoveAt  = VectorInt_RemoveAt;
//     vector.LookAt    = VectorInt_LookAt;

//     return vector;
// }