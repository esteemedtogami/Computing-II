#include "status.h"

//10:28

struct public_vector; //fprward declaration
typedef struct public_vector Public_vector;
typedef Public_vector* VECTOR;

struct public_vector
{
    Status (*push_back)(VECTOR hVector, int item);
    int (*get_size)(VECTOR hVector);
    int (*get_capacity)(VECTOR hVector);
    Status (*pop_back)(VECTOR hVector);
    int* (*at)(VECTOR hVector, int index);
    void (*destroy)(VECTOR* phVector);
};



 
//typedef void* VECTOR;



VECTOR vector_init_default(void);
