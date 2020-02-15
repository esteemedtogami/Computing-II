/*************************************
    Author: Sam Pickell
    Date: 2/04/16
    Effort: 50 minutes
    Purpose: By building off of Daily 4,
    simulate an array of 160 bits even
    though the array only contains 5 variables.
**************************************/

#include <stdio.h>
#include <stdlib.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_32_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);
int main(int argc, char* argv[])
{
    unsigned int flag_holder[5] = { 0 };//Set the first integer to zero and all others to zero by default.
    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);
    display_flags(flag_holder, 5);
    printf("\n\n");
    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);
    display_flags(flag_holder, 5);
    return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position)
{
    int i;
     
    i = flag_position / (sizeof(int)*8);
    flag_holder[i] |= (1 << flag_position);
    
    return;
}

void unset_flag(unsigned int flag_holder[], int flag_position)
{
    int i;
    
    i = flag_position / (sizeof(int)*8);
    flag_holder[i] &= ~(1 << flag_position);
    
    return;
}

int check_flag(unsigned int flag_holder[], int flag_position)
{
    int iReturn;
    int i;
    
    i = flag_position / (sizeof(int)*8);
    
    if ((flag_holder[i] >> flag_position) & 1)
    {
        iReturn = 1;
    }
    else
    {
        iReturn = 0;
    }
    
    return iReturn;
}

void display_32_flags_as_array(unsigned int flag_holder)
{
    int i, j = 31;
    
    for(i=0; i<=31; i++)
    {
        printf("%d", check_flag(&flag_holder, i));
        if(j%4 == 0)
        {
            printf(" ");
        }
        j --;
    }
    printf("\n");
}

void display_flags(unsigned int flag_holder[], int size)
{
    int i;
    
    for (i = 0; i < size; i++)
    {
        display_32_flags_as_array(flag_holder[i]);
    }
}