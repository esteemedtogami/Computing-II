#include <stdlib.h>
#include <stdio.h>
#include "string.h"

STRING string_init_default_function(int capacity)
{
    String* pString = (String*)malloc(sizeof(String));
    if(pString)
    {
        pString->capacity = 7;
        pString->char_arr = (char*)malloc(sizeof(char)*pString->capacity);
        if(!pString->char_arr)
        {
            free(pString);
            pString = NULL;
        }
        pString->size = 0;
    }
    return pString;
}

STRING string_init_c_string(char* str)
{
    int i = 0;
    String* pString = (String*)malloc(sizeof(String));
    if (pString)
    {
        while(str[i] != '\0')
        {
            i ++;
        }
        pString->capacity = i;
        pString->size = i-1;
        pString->char_arr = (char*)malloc(sizeof(char)*pString->capacity);
        if(!pString->char_arr)
        {
            free(pString);
            pString = NULL;
        }
        for (i = 0; i < pString->capacity; i++)
        {
            pString->char_arr[i] = str[i];
        }
    }
    return pString;
}

int string_compare(STRING str1, STRING str2)
{
    int comp = 0, i, j;
    String* pStr1 = (String*)str1;
    String* pStr2 = (String*)str2;
    
    
    if (pStr1->size > pStr2->size)
    {
        j = pStr1->size;
    }
    else
    {
        j = pStr2->size;
    }
    
    for (i = 0; i <= j; i++)
    {
        if ((pStr1->char_arr[i]) < (pStr2->char_arr[i]))
        {
            comp = -1;
            break;
        }
        else if ((pStr1->char_arr[i]) > (pStr2->char_arr[i]))
        {
            comp = 1;
            break;
        }
    }
    
    return comp;
}

void string_destroy(STRING* pPString)
{
    String* pString = (String*) *pPString;
    free(pString->char_arr);
    free(pString);
    *pPString = NULL;
}

int string_get_size(String* pString)
{
    return pString->size;
}

int string_get_capacity(String* pString)
{
    return pString->capacity;
}

Status string_extraction(FILE* file, String* pString)
{
    char c;
    char* copy;
    int i = 0;
    
    copy = (char*) malloc(sizeof(char) * pString->capacity);
    
    if (copy == NULL)
    {
        return FAILURE;
    }
    
    while (fscanf(file, " %c", &c) != -1)
    {
        if (c != ' ')
        {
            copy[i] = c;
            i ++;
        }
        if (c == ' ' && i != 0)
        {
            break;
        }
    }
    copy[i] = '\0';
    if (i == 0)
    {
        printf("This file is empty.\n");
        pString->size = 0;
        pString->char_arr[i] = '\0';
        free(copy);
        return 0;
    }
    
    if (i >= pString->capacity)
    {
        free(pString->char_arr);
        pString->char_arr = copy;
        pString->capacity = i + 1;
    }

    else
    {
        for (i = 0; copy[i] != '\0'; i++)
        {
            pString->char_arr[i] = copy[i];
            pString->char_arr[i] = '\0';
            free(copy);
        }
    }
    
    pString->size = i;
    return SUCCESS;
    
}


//ALMOST have it
 Status string_insertion(FILE* file, String* pString)
 {
     char c = 'c';
     int i, j = 0, size = 0;
     
     while (c != '\0')
     {
         c = pString->char_arr[j];
         j ++;
         size ++;
     }
     
     c = '\0';
     
     if (c != '\0')
     {
         printf("Something went wrong.\n");
         return FAILURE;
     }
     
     for (i = 0; i < size; i++)
     {
         c = pString->char_arr[i];
         if(fputc(c, file) == EOF)
         {
             printf("Reached eof\n");
             return FAILURE;
         }
     }
     

     return SUCCESS;
 }

void clear_keyboard_buffer(void)
{
    char c;
    
    do
    {
        
        scanf("%c", &c);
        
    } while (c != '\n');
    
}