typedef void* STRING;

STRING string_init_default_function(void);

STRING string_init_c_string(char* c_string);

void string_destroy(STRING* pPString);

int string_compare(STRING str1, STRING str2);

struct string
{
    char* char_arr;
    int capacity;
    int size;
};

typedef struct string String;
