#include <stdlib.h>
#include <stdio.h>
#include "string.h"

struct string
{
    char* char_arr;
    int capacity;
    int size;
};

typedef struct string String;

STRING string_init_default()
{
    String* pString = (String*)malloc(sizeof(String));
    if(pString)
    {
        pString->capacity = 1;
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

STRING string_init_c_string(char* c_str)
{
    int i = 0;
    String* pString = (String*)malloc(sizeof(String));
    if (pString)
    {
        while(c_str[i] != '\0')
        {
            i ++;
        }
        pString->capacity = i + 1;
        pString->size = i;
        pString->char_arr = (char*)malloc(sizeof(char)*pString->capacity);
        if(!pString->char_arr)
        {
            free(pString);
            pString = NULL;
        }
        for (i = 0; i < pString->capacity; i++)
        {
            pString->char_arr[i] = c_str[i];
        }
    }
    return pString;
}

int string_compare(STRING hString1, STRING hString2)
{
    int comp = 0, i, j;
    String* pStr1 = (String*)hString1;
    String* pStr2 = (String*)hString2;
    
    
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

Status string_destroy(STRING* phString)
{
    
    if ((*phString)->char_arr)
    {
        free((*phString)->char_arr);
        free((*phString));
        phString = NULL;
        // printf("Successful destory string\n");
    }
    else
    {
        // printf("Failed to destory string\n");
        return FAILURE;
    }
    return SUCCESS;
}

int string_get_size(STRING hString)
{
    return hString->size;
}

int string_get_capacity(STRING hString)
{
    return hString->capacity;
}

Status string_extraction(STRING hString, FILE* fp)
{
    char c;
    char* copy;
    int i = 0;
    String* pString = (String*) hString;
    
    if (fp == NULL)
    {
        printf("Failed to read file.\n");
        return FAILURE;
    }
    
    while (fscanf(fp, "%c", &c) != -1)
    {
        if (c == ' ' && i != 0)
        {
            ungetc(c, fp);
            break;
        }
        
        if (c != ' ')
        {
            pString->char_arr[i] = c;
            i ++;
            pString->size = i;
        }
        if (i == pString->capacity)
        {
            copy = (char*)malloc(sizeof(char) * pString->capacity);
            for (i = 0; i < pString->size; i++)
            {
                copy[i] = pString->char_arr[i];
            }
            free(pString->char_arr);
            pString->capacity = pString->capacity * 2;
            pString->char_arr = (char*)malloc(sizeof(char) * pString->capacity);
            for (i = 0; i < pString->size; i++)
            {
                pString->char_arr[i] = copy[i];
            }
            free(copy);
        }

    }
    
    
    if (i == 0)
    {
        pString->size = 0;
        // printf("File is empty.\n");
        return FAILURE;
    }
    
    pString->char_arr[i] = '\0';
    
    return SUCCESS;
}

Status string_insertion(STRING hString, FILE* fp)
{
    int i = 0;
    char c;
    String* pString = (String*) hString;
    if (fp == NULL)
    {
        return FAILURE;
    }
    
    for (i = 0; i < pString->size; i++)
    {
        c = (pString->char_arr[i]);
        fprintf(fp, "%c", c);
    }
    
    return SUCCESS;
}

Status string_push_back(STRING hString, char item)
{
    int i;
    char* copy;
    String* pString = (String*) hString;
    
    if (pString->size == pString->capacity - 1)
    {
        copy = (char*) malloc(sizeof(char) * pString->capacity * 2);
        for (i = 0; i < pString->size; i++)
        {
            copy[i] = pString->char_arr[i];
        }
        copy[i] = '\0';
        
        free(pString->char_arr);
        pString->char_arr = copy;
        pString->capacity = pString->capacity * 2;
    }
    
    pString->char_arr[pString->size] = item;
    pString->char_arr[pString->size + 1] = '\0';
    pString->size ++;
    
    return SUCCESS;
    
}

Status string_pop_back(STRING hString)
{
    String* pString = (String*) hString;
    
    if (pString->size <= 0)
    {
        return FAILURE;
    }
    
    pString->char_arr[pString->size] = '\0';
    pString->size--;
    return SUCCESS;
}

char* string_at(STRING hString, int index)
{
    String* pString = (String*) hString;
    
    if (index < 0 || index > pString->size - 1)
    {
        return NULL;
    }
    
    return &(pString->char_arr[index]);
}

char* string_c_str(STRING hString)
{
    int i;
    char* copy;
    String* pString = (String*) hString;
    
    if (pString->char_arr[pString->size - 1] != '\0')
    {
        copy = (char*) malloc(sizeof(char) * pString->capacity + 1);
        for (i = 0; i < pString->size; i++)
        {
            copy[i] = pString->char_arr[i];
        }
        copy[i] = '\0';
        
        free(pString->char_arr);
        pString->char_arr = copy;
        pString->capacity = pString->capacity + 1;
    }
    
    pString->char_arr[pString->size] = '\0';
    
    return &(pString->char_arr[0]);
}

Status string_concat(STRING hResult, STRING hAppend)
{
    String* pResult = (String*) hResult;
    String* pAppend = (String*) hAppend;
    
    char* temp;
    int i;
    
    if (pAppend->size == 0)
    {
        return FAILURE;
    }
    else if (pResult->size == 0)
    {
        for (i = 0; i < pAppend->size; i++)
        {
            pResult->char_arr[i] = pAppend->char_arr[i];
        }
        pResult->size = pAppend->size;
        pResult->capacity = pResult->size + 1;
    }

    else
    {
        int iSize = pResult->size + pAppend->size + 1, iCapacity = iSize + 1, j;
        
        temp = (char*)malloc(sizeof(char) * iCapacity);
        if (temp == NULL)
        {
            return FAILURE;
        }
        for (i = 0; i < pResult->size; i++)
        {
            temp[i] = pResult->char_arr[i];
        }
        
        temp[i] = ' ';
        
        j = pResult->size + 1;
        
        for (i = 0; i < pAppend->size; i++)
        {
            temp[j + i] = pAppend->char_arr[i];
        }
        temp[j + i] = '\0';
        free(pResult->char_arr);
        pResult->char_arr = temp;
        pResult->capacity = iCapacity;
        pResult->size = iSize;

    }
    
    return SUCCESS;
    
}

Boolean string_empty(STRING hString)
{
    String* pString = (String*) hString;
    
    return ((Boolean) pString->size == 0);
}

void clear_keyboard_buffer(void)
{
    char c;
    
    do
    {
        
        scanf("%c", &c);
        
    } while (c != '\n');
    
}


