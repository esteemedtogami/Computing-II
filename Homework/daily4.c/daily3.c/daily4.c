/*************************************
    Author: Sam Pickell
    Date: 2/01/16
    Effort: 1 Hour, 38 minutes
    Purpose: Use bitwise operations to
        set a binary value in a variable
        by going to the nth number in the
        sequence and changing its value or
        change it back by unsetting it, then
        print the sequence to the screen.
**************************************/

#include <stdio.h>
#include <stdlib.h>

void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int * flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);

int main(int argc, char* argv[])
{
    unsigned int flag_holder = 0;
    
    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);
    
    display_32_flags(flag_holder);
    
    unset_flag(&flag_holder, 31);
    unset_flag(&flag_holder, 3);
    set_flag(&flag_holder, 9);
    
    display_32_flags(flag_holder);
    return 0;
}

void set_flag(unsigned int* flag_holder, int flag_position)
{
    *flag_holder |= (1 << flag_position);
    
    return;
}

void unset_flag(unsigned int* flag_holder, int flag_position)
{
    *flag_holder &= ~(1 << flag_position);
    
    return;
}

int check_flag(unsigned int flag_holder, int flag_position)
{
    int iReturn;
    
    if ((flag_holder >> flag_position) & 1)
    {
        iReturn = 1;
    }
    else
    {
        iReturn = 0;
    }
    
    return iReturn;
}

void display_32_flags(unsigned int flag_holder)
{
    int i;
    
    for(i=31; i>=0; i--)
    {
        printf("%d", check_flag(flag_holder, i));
        if(i%4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}