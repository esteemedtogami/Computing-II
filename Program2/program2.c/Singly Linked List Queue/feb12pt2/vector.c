#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct vector
{
    //public
    Status (*push_back)(VECTOR hVector, int item);
    int (*get_size)(VECTOR hVector);
    int (*get_capacity)(VECTOR hVector);
    Status (*pop_back)(VECTOR hVector);
    int* (*at)(VECTOR hVector, int index);
    void (*destroy)(VECTOR* phVector);
    
    //private
    int size;
    int capacity;
    int* data;
};

typedef struct vector Vector;


//put something into container

//precondition: hVector must hold the address of a valid object.
//postcondition: item is placed at the end of the vector.
//  Returns SUCCESS if the push_back worked or FAILURE otherwise
Status vector_push_back(VECTOR hVector, int item);

//precondition: hVector must hold the address of a valid object.
//postcondition: Returns the szie of the object referred to by
//      the handle hVector
int vector_get_size(VECTOR hVector);

//precondition: hVector must hold the address of a valid object.
//postcondition: Returns the capactity of the object referred to by
//      the handle hVector
int vector_get_capacity(VECTOR hVector);

//remove something from container

//precondition: hVector must hold the address of a valid object.
//postcondition: Removes the last element of the vector and returns SUCCESS OR FAILURE
Status vector_pop_back(VECTOR hVector);

//precondition: hVector must hold the address of a valid object.
//postcondition: Returns address of the index_th element if index is in rangeand NULL otherwise
int* vector_at(VECTOR hVector, int index);

//shrink to fit

//look at or change the volume of an item
//list items
//sort items


void vector_destroy(VECTOR* phVector);

//initializer for a vector
VECTOR vector_init_default(void)
{
    Vector* pVector;
    pVector = (Vector*)(malloc(sizeof(Vector)));
    
    if (pVector != NULL)
    {
        pVector->size = 0; //must be a pointer to a struct
        pVector->capacity = 1;
        pVector->data = malloc(sizeof(int) * pVector->capacity);
        //not good
        if(pVector->data == NULL)//not good
        {
            free(pVector);
            pVector = NULL;
        }
        
        pVector->push_back = vector_push_back;
        pVector->get_size = vector_get_size;
        pVector->get_capacity = vector_get_capacity;
        pVector->pop_back = vector_pop_back;
        pVector->at = vector_at;
        pVector->destroy = vector_destroy;
    }
    
    return pVector;
}

Status vector_push_back(VECTOR hVector, int item)
{
    Vector* pVector = (Vector*)hVector;
    int* pTemp;
    int i;
    
    //if there is not enough room, make it bigger
    if (pVector->size >= pVector->capacity)
    {
        pTemp = (int*)malloc(sizeof(int)*pVector->capacity * 2);
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
    pVector->data[pVector->size] = item;
    //increase size
    pVector->size++;
    return SUCCESS;
    
}

int vector_get_size(VECTOR hVector)
{
    Vector* pVector = (Vector*)hVector;
    
    return pVector->size;
}


int vector_get_capacity(VECTOR hVector)
{
    Vector* pVector = (Vector*)hVector;
    
    return pVector->capacity;
}

Status vector_pop_back(VECTOR hVector)
{
    Vector* pVector = (Vector*)hVector;
    
    if (pVector->size <= 0)
    {
        return FAILURE;
    }
    
    pVector->size--;
    return SUCCESS;
}

int* vector_at(VECTOR hVector, int index)
{
    Vector* pVector = (Vector*)hVector;
    
    if(index < 0 || index > pVector->size-1)
    {
        return NULL;
    }
    
    return &(pVector->data[index]);
}

void vector_destroy(VECTOR* phVector)
{
    Vector* pVector = (Vector*) *phVector;
    
    if (pVector)
    {
        free(pVector->data);
        free(pVector);
    }
    *phVector = NULL;
    
    return;
}