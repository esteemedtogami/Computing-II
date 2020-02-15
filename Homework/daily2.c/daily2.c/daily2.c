/***********************************
    Author: Sam Pickell
    Date: 1/25/16
    Effort: 15 minutes
    Purpose: Using the left shift
        operator, shift x to the
        left one bit and store
        this new number in x, then
        repeating this until x = 0.
***********************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int x = 1, y = 0;
    
    for (;;)
    {
        if (x == 0)
        {
            break;
        }
        printf("%d: %u\n", y, x);
        y++;
        x = x<<1;
    }
    
    
    return 0;
}