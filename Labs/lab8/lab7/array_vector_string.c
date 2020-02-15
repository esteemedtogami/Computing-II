

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "vector_string.h"
#include "array_vector_string.h"

VECTOR* load_array_vector_string(FILE* words)
{
    
    VECTOR* pVector = malloc(sizeof(VECTOR) * 30);
    
    if (pVector)
    {
        int i = 0;
        for (i = 0; i < 30; i++)
        {
            pVector[i] = vector_string_init_default();
        }


        STRING pString = string_init_default();

        while(string_extraction(pString, words))
        {
            if (pString->size >= 30)
            {
                printf("The array size is larger than 29.\n");
                exit(1);
            }
            
            STRING temp = (STRING)malloc(sizeof(String));
            temp->capacity = pString->capacity;
            temp->size = pString->size;
            temp->char_arr = (char*)malloc(sizeof(char)*temp->capacity);
            for (i = 0; i < pString->size; i++)
            {
                temp->char_arr[i] = pString->char_arr[i];
            }
            temp->char_arr[i] = '\0';
            
            vector_string_push_back(pVector[pString->size - 1], temp);
        }
        string_destroy(&pString);
    }

return (VECTOR*)pVector;
}

void array_vector_string_destroy(VECTOR** pArray)
{
    int i;
    
    if (pArray)
    {
        for (i = 0; i < 30; i++)
        {
            vector_string_destroy(&((*pArray)[i]));
        }
        
        free(*pArray);
        pArray = NULL;
    }
    
}