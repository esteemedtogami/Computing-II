enum status {FAILURE, SUCCESS};

typedef enum status Status;

typedef void* STRING;

struct string
{
    char* char_arr;
    int capacity;
    int size;
};

typedef struct string String;

STRING string_init_default_function(int capacity);

STRING string_init_c_string(char* str);

void string_destroy(STRING* pPString);

int string_compare(STRING str1, STRING str2);

int string_get_size(String* pString);

int string_get_capacity(String* pString);

Status string_extraction(FILE* file, String* pString);

Status string_insertion(FILE* file, String* pString);

void clear_keyboard_buffer(void);