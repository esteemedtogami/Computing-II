#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "vector_string.h"
#include "array_vector_string.h"

int main(int argc, char* argv[])
{
    FILE* fp;
    VECTOR* pvString;
    VECTOR vString;
    
    fp = fopen("dictionary.txt", "r");
    pvString = load_array_vector_string(fp);
    
    vString = pvString[1];
    printf("The first string in vector string 1 is: %s\n", string_c_str(*(vector_string_at(vString, 0))));
    
    array_vector_string_destroy(&pvString);
    fclose(fp);
    
    return 0;
}

