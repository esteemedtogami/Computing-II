#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "string.h"
#include "vector_string.h"

struct vector_string
{
    int size;
    int capacity;
    STRING* data;
};

typedef struct vector_string Vector_string;
typedef Vector_string* VECTOR;

VECTOR vector_string_init_default(void)
{
    Vector_string* pVector;
    pVector = (Vector_string*) malloc(sizeof(Vector_string));
    
    if (pVector != NULL)
    {
        pVector->size = 0;
        pVector->capacity = 0;
        pVector->data = malloc(sizeof(STRING));
        
        if (pVector->data == NULL)
        {
            free (pVector);
            pVector = NULL;
        }
    }
    
    return (VECTOR)pVector;
}

void vector_string_destroy(VECTOR* phVectorString)
{
    //Vector_string* pVector = (Vector_string*) *phVectorString;
    //int i;
    
    if (phVectorString)
    {
        if ((*phVectorString)->data)
        {
            int i = 0;
            while (i < (*phVectorString)->size)
            {
                string_destroy(&((*phVectorString)->data[i]));
                i ++;
            }
            free((*phVectorString)->data);
        }
        free(*phVectorString);
        phVectorString = NULL;
    }
    
}

Status vector_string_push_back(VECTOR hVectorString, STRING hString)
{
    Vector_string* pVector = (Vector_string*)hVectorString;
    STRING* pTemp;
    int i;
    
    //if there is not enough room, make it bigger
    if (pVector->size >= pVector->capacity)
    {
        if (pVector->capacity == 0)
        {
            pVector->capacity = 1;
        }
        
        pTemp = (STRING*)malloc(sizeof(STRING)*pVector->capacity * 2);
        if (pTemp == NULL)
        {
            return FAILURE;
        }
        else
        {
            for (i = 0; i < pVector->size; i++)
            {
                pTemp[i] = pVector->data[i];
            }
            
            free(pVector->data);
            pVector->data = pTemp;
            pVector->capacity *= 2;
        }
    }
    //put the item in
    //place item at size
    pVector->data[pVector->size] = hString;
    //increase size
    pVector->size++;
    return SUCCESS;
}

int vector_string_get_size(VECTOR hVectorString)
{
    Vector_string* pVector = (Vector_string*) hVectorString;
    
    return pVector->size;
}

int vector_string_get_capacity(VECTOR hVectorString)
{
    Vector_string* pVector = (Vector_string*) hVectorString;
    
    return pVector->capacity;
}

Boolean vector_string_empty(VECTOR hVectorString)
{
    Vector_string* pVector = (Vector_string*)hVectorString;
    
    return (Boolean) (pVector->size == 0);
}

STRING* vector_string_at(VECTOR hVectorString, int index)
{
    Vector_string* pVector = (Vector_string*)hVectorString;
    
    if (index < 0 || index > pVector->size - 1)
    {
        return NULL;
    }
    
    return &(pVector->data[index]);
}

