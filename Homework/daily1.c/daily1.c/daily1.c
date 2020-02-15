/**************************
 Author: Sam Pickell
 Date: 1/21/16
 
 Purpose: Reverse c-string
 Time Spent: 4:15 - 5:17
**************************/

#include <stdio.h>

char* reverse(char array[]);

int main(int argc, char* argv[])
{
    char word[] = "Happy Birthday!";
    
    printf("%s\n", word);
    reverse(word);
    printf("%s\n", word);
    printf("%s\n", reverse(word));
    printf("%s\n", word);
    return 0;
}


char* reverse(char array[])
{
    int size = 0, i = 0, j = 0;
    
    while (array[size] != '\0')
    {
        ++size;
    }
    
    char backward[size - 1];
    
    while (i < size)
    {
        backward[i] = array[i];
        i++;
    }
    
    i -= 1;
    
    while (i >= 0)
    {
        array[j] = backward[i];
        j ++;
        i --;
    }
    
    return array;
}
