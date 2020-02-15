#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "vector_string.h"

int main(int argc, char* argv[])
{
    STRING hString1, hString2, hString3;
    
    char* sen1 = "1. First sentence";
    hString1 = string_init_c_string(sen1);
    char* sen2 = "2. Second sentence";
    hString2 = string_init_c_string(sen2);
    char* sen3 = "3. Third sentence";
    hString3 = string_init_c_string(sen3);
    
    printf("*************** lab7 ********************\n");
    VECTOR VectorString = vector_string_init_default();
    printf("The size of the empty vector: %d\n", vector_string_get_size(VectorString));
    printf("The capacity of the empty vector: %d\n", vector_string_get_capacity(VectorString));
    printf("Is the Vector empty? %d\n", vector_string_empty(VectorString));
    
    vector_string_push_back(VectorString, hString1);
    vector_string_push_back(VectorString, hString2);
    vector_string_push_back(VectorString, hString3);
    printf("Is the Vector empty? %d\n", vector_string_empty(VectorString));
    printf("The size of the vector: %d\n", vector_string_get_size(VectorString));
    printf("The capacity of the vector: %d\n", vector_string_get_capacity(VectorString));
    printf("%s\n", string_c_str(*(vector_string_at(VectorString, 1))));
    
    vector_string_destroy(&VectorString);
    
    return 0;
}

