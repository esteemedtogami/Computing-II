/**********************************************************************
 Program: daily7.c
 Author: Sam Pickell
 Date: 2/26/16
 Time spent: 5 hours
 Purpose: The purpose of this program is to accept any number of strings
    of parentheses using a linked stack and check to see if the statement 
    is valid. If a right parenthese (or bracket or brace) is encountered,
    the top of the stack is checked. If it matches, it is popped and the
    program continues. Otherwise, it fails.
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

enum status { FAILURE, SUCCESS };
enum boolean { FALSE, TRUE};

typedef enum status Status;
typedef enum boolean Boolean;

struct public_stack;
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

struct node;
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
    Status (*push)(STACK hStack, char item);
    Status (*pop)(STACK hStack);
    char (*top)(STACK hStack, Status* pStatus_code);
    Boolean (*empty)(STACK hStack);
    void (*destroy)(STACK* phStack);
    
    Node* head;
};

typedef struct stack Stack;

#define SIZE 128

void clear_keyboard_buffer(void);

Status parenthese_balance(STACK hStack, char* array);

int main(int argc, char* argv[])
{
    int iRunTimes, i;
    scanf("%d", &iRunTimes);
    clear_keyboard_buffer();
    
    for (i = 0; i < iRunTimes; i++)
    {
        STACK hStack = stack_init_default();
        char array[SIZE];
        array[SIZE - 1] = '\0';
        fgets(array, sizeof(array), stdin);
        parenthese_balance(hStack, array);
        if (!(stack_empty(hStack)))
        {
            stack_destroy(&hStack);
        }
    }
    
    
    
    return 0;
}

void clear_keyboard_buffer(void)
{
    
    char c;
    
    do
    {
        scanf("%c", &c);
    } while(c != '\n');
}

Status parenthese_balance(STACK hStack, char* array)
{
    int i = 0;
    char c = 'y';
    
    
    Status status;
    
    while (array[i] != '\n')
    {
        if ((array[i] == '(') || (array[i] == '[') || (array[i] == '{'))
        {
            hStack->push(hStack, array[i]);
            
        }
        else if ((array[i] == ')') || (array[i] == ']') || (array[i] == '}'))
        {
            if (((hStack->top(hStack, &status) == '(') ||
                 ((hStack->top(hStack, &status) == '[') ||
                  ((hStack->top(hStack, &status) == '{')))))
            {
                hStack->pop(hStack);
            }
            
            else
            {
                c = 'n';
                break;
            }
        }
        i ++;
    }
    
    if (((hStack->top(hStack, &status) == ')') ||
         ((hStack->top(hStack, &status) == ']') ||
          ((hStack->top(hStack, &status) == '}')))))
    {
        c = 'n';
    }
    
    if ((array[i - 1] == '(') || (array[i - 1] == '[') || (array[i - 1] == '{'))
    {
        c = 'n';
    }
    
    
    if (!(hStack->empty(hStack)))
    {
        c = 'n';
    }
    
    
    if (c == 'y')
    {
        printf("Yes\n");
        return SUCCESS;
    }
    else
    {
        printf("No\n");
        hStack->destroy(&hStack);
        return FAILURE;
    }
}




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
    free(pStack);
    *phStack = NULL;
    
    return;
}




