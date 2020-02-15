
#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

struct node; //forward declaration
typedef struct node Node;

struct node
{
    char data;
    Node* next;
    
};

Status stack_push(STACK hStack, char item);
Status stack_pop(STACK hStack);
char stack_top(STACK hStack, Status* pStatus_code);
Boolean stack_empty(STACK hStack);
void stack_destroy(STACK* phStack);


struct stack
{
    //public
    Status (*push)(STACK hStack, char item);
    Status (*pop)(STACK hStack);
    char (*top)(STACK hStack, Status* pStatus_code);
    Boolean (*empty)(STACK hStack);
    void (*destroy)(STACK* phStack);
    
    //private
    Node* head;
};

typedef struct stack Stack;

STACK stack_init_default(void)
{
    Stack* pStack;
    
    pStack = (Stack*)(malloc(sizeof(Stack)));
    if (pStack != NULL)
    {
        pStack->push = stack_push;
        pStack->pop = stack_pop;
        pStack->top = stack_top;
        pStack->empty = stack_empty;
        pStack->destroy = stack_destroy;
        
        
        pStack->head = NULL;
    }
    return (STACK) pStack;
}

Status stack_push(STACK hStack, char item)
{
    Stack* pStack = (Stack*) hStack;
    Node* temp;
    
    temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)
    {
        return FAILURE;
    }
    temp->data = item;
    temp->next = pStack->head;
    
    pStack->head = temp;
    
    //head insert
    return SUCCESS;
}
Status stack_pop(STACK hStack)
{
    Stack* pStack = (Stack*)hStack;
    Node* temp;
    
    if (pStack->head == NULL)
    {
        return FAILURE;
    }
    
    temp = pStack->head;
    pStack->head = pStack->head->next;
    free(temp);
    return SUCCESS;
}
char stack_top(STACK hStack, Status* pStatus_code)
{
    Stack* pStack = (Stack*)hStack;
    
    if (pStack->head == NULL)
    {
        *pStatus_code = FAILURE;
        return 'n';
    }
    
    *pStatus_code = SUCCESS;
    return pStack->head->data;
}
Boolean stack_empty(STACK hStack)
{
    Stack* pStack = (Stack*)hStack;
    
    return (Boolean) (pStack->head == NULL);
}
void stack_destroy(STACK* phStack)
{
    Stack* pStack = (Stack*) *phStack;
    Node* temp;
    
    temp = pStack->head;
    while (temp != NULL)
    {
        pStack->head = pStack->head->next;
        free(temp);
        temp = pStack->head;
    }
    
    //PROGRAM 1
    free(pStack);
    *phStack = NULL;
    
    return;
}


