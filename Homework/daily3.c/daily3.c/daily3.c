/*************************************
    Author: Sam Pickell
    Original Submit Date: 1/29/16
    Resubmit Date: 2/01/16
    Effort: 2 hours and 58 minutes
    Purpose: Use bitwise operations to
        set a binary value in a variable
        by going to the nth number in the
        sequence and changing its value, then
        print the sequence to the screen.
    Reason for Resubmit: While working
        on Daily 4, I figured out what the
        nth bit meant and was able to adjust
        code to function as originally asked;
        checking to see if the bit itself
        was a 1 or a 0 and to print accordingly.
        My original program only checked to see
        if flag_position was the number sent
        to set_flag.
**************************************/

#include <stdio.h>
#include <stdlib.h>

void set_flag(int* flag_holder, int flag_position);
int check_flag(int flag_holder, int flag_position);

int main(int argc, char* argv[])
{
    int flag_holder = 0;
    int i;
    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);
    for(i=31; i>=0; i--)
    {
        printf("%d", check_flag(flag_holder, i));
        if(i%4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}

void set_flag(int* flag_holder, int flag_position)
{
    *flag_holder |= 1 << flag_position;
    
    return;
}

int check_flag(int flag_holder, int flag_position)
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