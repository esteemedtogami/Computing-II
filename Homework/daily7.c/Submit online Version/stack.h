#ifndef STACK_H
#define STACK_H
#include "status.h"

struct public_stack; //forward declaration
typedef struct public_stack Public_stack;
typedef Public_stack* STACK;

struct public_stack
{
    Status (*push)(STACK hStack, char item);
    Status (*pop)(STACK hStack);
    char (*top)(STACK hStack, Status* pStatus_code);
    Boolean (*empty)(STACK hStack);
    void (*destroy)(STACK* phStack);
};


STACK stack_init_default(void);



#endif