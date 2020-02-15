#include <stdio.h>
#include <stdlib.h>
#include "string.h"

//Simple.txt file includes the following sentence:
//The quick brown fox jumped over the lazy dogs.
//No spaces or newlines after that period
int main(int argc, char* argv[])
{
    String* hString;
    /*
    FILE* fp;
    printf("*************************************************\n");
    printf("This is Check Point 1.\n");
    printf("*************************************************\n");
    hString = string_init_default();
    fp = fopen("simple.txt", "r");
    while (string_extraction(fp, hString))
    {
        string_insertion(stdout, hString);
        printf("\n");
        if (fgetc(fp) == ' ')
        {
            printf("Found a space after the string\n");
        }
    }
    string_destroy(&hString);
    fclose(fp);
    */
    printf("*************************************************\n");
    printf("This is Check Point 2.\n");
    printf("*************************************************\n");
    
    hString = string_init_c_string("Hello World!");
    string_insertion(stdout, hString);
    printf("\n");
    printf("String size: %d \n\n", string_get_size(hString));
    string_push_back(hString, ' ');
    string_push_back(hString, 'N');
    string_push_back(hString, 'e');
    string_push_back(hString, 'W');
    string_insertion(stdout, hString);
    printf("\n");
    printf("String size: %d \n\n", string_get_size(hString));
    string_pop_back(hString);
    string_insertion(stdout, hString);
    printf("\n");
    printf("String size: %d \n\n", string_get_size(hString));
    string_pop_back(hString);
    string_pop_back(hString);
    string_pop_back(hString);
    string_insertion(stdout, hString);
    printf("\n");
    printf("String size: %d \n", string_get_size(hString));
    string_destroy(&hString);
    
    return 0;
    
}

//NOTE FOR LATER ALL STRING EXTRACTION SHOULD BE STRING INSERTION