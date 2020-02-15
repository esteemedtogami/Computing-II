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
#include "stack.h"

#define SIZE 1000

void clear_keyboard_buffer(void);

Status parenthese_balance(STACK hStack, char* array);

int main(int argc, char* argv[])
{
    int iRunTimes, i;
    //printf("Enter the number of times this will run: ");
    scanf("%d", &iRunTimes);
    clear_keyboard_buffer();
    
    //printf("%d\n", iRunTimes);
    
    for (i = 0; i < iRunTimes; i++)
    {
        STACK hStack = stack_init_default();
        char array[SIZE];
        array[SIZE - 1] = '\0';
        //printf("Enter string: ");
        fgets(array, sizeof(array), stdin);
        parenthese_balance(hStack, array);
        if (!(hStack->empty(hStack)))
        {
            hStack->destroy(&hStack);
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
        
        
        //printf("This is the top: %c\n", hStack->top(hStack, &status));
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

