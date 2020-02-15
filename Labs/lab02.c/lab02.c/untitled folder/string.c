#include <stdlib.h>
#include <stdio.h>
#include "string.h"

STRING string_init_default_function(void)
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


