/***********************************************************************
Program: daily8.c
Author: Sam Pickell
Date: March 29, 2016
Time spent: 4 hours and 30 minutes
Purpose: The purpose of this program is to use the string object that we
    built in lab to read in a string from a file and determine if it 
    is a palindrome or not.
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"

int is_palindrome(FILE* fp);

int main(int argc, char* argv[])
{
    FILE* fp;
    
    fp = fopen("Sample.txt", "r");
    
    if (is_palindrome(fp))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    
    fclose(fp);
    
    return 0;
}

int is_palindrome(FILE* fp)
{
    STRING str1 = string_init_default();
    int size_of_string = 0;
    
    get_line(str1, fp);
    
    int count = string_get_size(str1);
    
    //convert
    int j;
    STRING str2 = string_init_default();
    
    for (j = 0; j < count; j++)
    {
        if (isalpha(*string_at(str1, j)))
        {
          string_push_back(str2, toupper(*string_at(str1, j)));
            size_of_string ++;
        }
    }
    
    str1 = str2;
    
    int startIndex = 0, endIndex = size_of_string - 1;
    
        if (*string_at(str1, startIndex) == *string_at(str1, endIndex))
        {
            while (*string_at(str1, startIndex) == *string_at(str1, endIndex) &&
                startIndex <= (string_get_size(str1) / 2))
            {
                if (endIndex % 2 != 0)
                {
                    if (startIndex == endIndex - 1)
                    {
                        endIndex -= 1;
                        break;
                    }
                        
                }
                
                if (*string_at(str1, startIndex) != *string_at(str1, endIndex) || startIndex == endIndex)
                {
                    break;
                }
                startIndex ++;
                endIndex --;
            }
            
        }
    
    
    string_destroy(&str1);
    //string_destroy(&str2);
    
    
   if (startIndex == endIndex)
   {
       return 1;
   }
   else
   {
       return 0;
   }
    
}