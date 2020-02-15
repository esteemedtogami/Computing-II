/**********************************
 Author: Sam Pickell
 Date: 2/15/16
 Effort: 7 hours and 10 minutes,
 Purpose: Creating an opaque object that can
    dynamically create an array and set
    the elements in that array to 0s or
    1s to act as bits.
 Reason for Resubmit: Improper use of malloc,
    used sizeof(int) when resizing capacity.
 Interface Proposal: Include a function that
    displays the data, such as display_flags
    from the earlier dailies.
**********************************/


#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"

struct bit_flags
{
    int size;
    int capacity;
    int* data;
};

typedef struct bit_flags Bit_flags;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
    Bit_flags* pBit_flags;
    int i;
    
    pBit_flags = (Bit_flags*) (malloc(sizeof(Bit_flags)));
    
    if (pBit_flags == NULL || number_of_bits < 1)
    {
        printf("init_number_bits says: FAILURE\n");
        return FAILURE;
    }
    else
    {
        pBit_flags->size = number_of_bits;
        pBit_flags->capacity = number_of_bits + 1;
        pBit_flags->data = malloc(sizeof(int) * pBit_flags->size);
        
        if (pBit_flags->data == NULL)
        {
            free(pBit_flags);
            pBit_flags = NULL;
        }
        
        for (i = 0; i < pBit_flags->size; i++)
        {
            pBit_flags->data[i] = 0;
        }
    }
    
    return (BIT_FLAGS) pBit_flags;
}


Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    int* pTemp;
    Bit_flags* pBit_flags = (Bit_flags*) hBit_flags;
    int i, j = pBit_flags->size;
    
    //if there is not enough room, make it bigger
    if (flag_position >= pBit_flags->capacity)
    {
        pTemp = (int*) malloc(sizeof(int) * (flag_position));
        if (pTemp == NULL)
        {
            printf("set_flag says: FAILURE\n");
            return FAILURE;
        }
        else
        {
            
            for (i = 0; i < pBit_flags->size; i++)
            {
                pTemp[i] = pBit_flags->data[i];
            }
            
            for (i = j; i <= flag_position; i++)
            {
                pTemp[i] = 0;
            }
            
            free(pBit_flags->data);
            
            pBit_flags->size = flag_position;
            pBit_flags->data = pTemp;
            pBit_flags->capacity = pBit_flags->capacity * (sizeof(int));
        }
    }
    //put the item in
    //place item at data[flag_position]
    
    pBit_flags->data[flag_position] = 1;
    
    return SUCCESS;
}


Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    int* pTemp;
    Bit_flags* pBit_flags = (Bit_flags*) hBit_flags;
    int i, j = pBit_flags->size;
    
    //if there is not enough room, make it bigger
    if (flag_position >= pBit_flags->capacity)
    {
        pTemp = malloc(sizeof(int) + (flag_position));
        if (pTemp == NULL)
        {
            printf("set_flag says: FAILURE\n");
            return FAILURE;
        }
        else
        {
            
            for (i = 0; i < pBit_flags->size; i++)
            {
                pTemp[i] = pBit_flags->data[i];
            }
            
            for (i = j; i <= flag_position; i++)
            {
                pTemp[i] = 0;
            }
            
            free(pBit_flags->data);
            
            pBit_flags->size = flag_position;
            pBit_flags->data = pTemp;
            pBit_flags->capacity = pBit_flags->capacity * (sizeof(int));
        }
    }
    //put the item in
    //place item at data[flag_position]
    
    pBit_flags->data[flag_position] = 0;
    
    return SUCCESS;
}


int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    int iReturn;
    Bit_flags* pBit_flags = (Bit_flags*) hBit_flags;
    
    if ((pBit_flags->data[flag_position] == 1 || pBit_flags->data[flag_position] == 0))
    {
        iReturn = pBit_flags->data[flag_position];
    }
    else
    {
        iReturn = -1;
    }
    
    return iReturn;
}


int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
    Bit_flags* pBit_flags = (Bit_flags*) hBit_flags;
    
    return pBit_flags->size;
}


int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
    Bit_flags* pBit_flags = (Bit_flags*) hBit_flags;
    
    return pBit_flags->capacity;
}


void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
    Bit_flags* pBit_flags = (Bit_flags*)*phBit_flags;
    
    if (pBit_flags)
    {
        free(pBit_flags->data);
        free(pBit_flags);
    }
    *phBit_flags = NULL;
    
    return;
}


