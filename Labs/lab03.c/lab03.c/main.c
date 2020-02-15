#include <stdlib.h>
#include <stdio.h>
#include "string.h"

int main(int argc, char* argv[])
{

    int size;
    FILE* file;

    file = fopen("test", "r");
    printf("Enter the length of the string: ");
    scanf("%d", &size);
    void clear_keyboard_buffer(void);
    STRING str = string_init_default_function(size);
    String* str1 = (String*) str;
    if (file == NULL)
    {
        printf("The file could not be opened.\n");
        string_destroy(&str);
        exit(1);
    }
    printf("Opening file \"test\"...\n");
    size = string_extraction(file, str1);
    printf("%d: get %s, size is %d, capacity is %d\n", size, str1->char_arr,
       string_get_size(str1), string_get_capacity(str1));
    fclose(file);
    string_destroy(&str);    
    
    file = fopen("test2", "w");
    void clear_keyboard_buffer(void);
    STRING str3 = string_init_default_function(size);
    String* str2 = (String*) str3;
    if (file == NULL)
    {
        printf("The file could not be opened.\n");
        string_destroy(&str3);
        exit(1);
    }
    
    printf("Enter String: ");
    scanf("%s", str2->char_arr);
    
    printf("%s\n", str2->char_arr);

    size = string_insertion(file, str2);
    fclose(file);
    string_destroy(&str3);
    
    return 0;
}
 
