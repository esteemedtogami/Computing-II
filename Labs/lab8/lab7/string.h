#ifndef STRING_H_
#define STRING_H_

#include <stdio.h>
#include "status.h"

//A handle to the struct string
//The struct string definition is located in
//the implementation file

struct string
{
    char* char_arr;
    int capacity;
    int size;
};


typedef struct string String;
typedef String* STRING;

//Precondition: None
//Postcondition: returns a handle to a valid string object
STRING string_init_default();

//Precondition: c_str is a c string to use to initialize the string object
//Postcondition: a handle to the string object
STRING string_init_c_string(char* c_str);

//Precondition: phString is a pointer to a handle to the string object
//Postcondition: Returns SUCCESS if we successfully freed
//the memory, FAILURE otherwise
Status string_destroy(STRING* phString);


//Precondition: hString1 and hString2 are handles to two different
//string objects to compare between them
//Postcondition: 0 both strings are equal
// < 0: the first character that does not match has a lower value in str1 than in str2
// > 0: the first character that does not match has a higher value in str1 than in str2
int string_compare(STRING hString1, STRING hString2);

//Precondition: hString is a handle to a string object
//Postcondition: the number of characters currently held by the string object
int string_get_size(STRING hString);

//Precondition: hString is a handle to a string object
//Postcondition: the maximum number of characters the string object can hold
int string_get_capacity(STRING hString);

//Precondition: hString is a handle to a string object, fp is a pointer
//to a file to read a string from
//Postcondition: SUCCESS if we successfully read a single string from the file,
//FAILURE if reached the EOF and string is still size zero
Status string_extraction(STRING hString, FILE* fp);

//Precondition: hString is a handle to a string object, fp is a pointer to
//a file to write a string to
//Postcondition: SUCCESS if it successfully wrote to the FILE* and
//FAILURE if it failed to do so
Status string_insertion(STRING hString, FILE* fp);

//Precondition: hString is a handle to a valid string object,
//item is a character to add to the end of the string
//Postcondition:
// return SUCCESS if the item is successfully
// added to the end of the string.
// The end of the string refers to the current size of the string.
// If the string reached its maximum capacity, i.e., size == capacity,
// then the string needed to be resized to be able to add the new item
// Resize the string by doubling its capacity
// Return FAILURE if the string could not be resized
Status string_push_back(STRING hString, char item);

//Precondition: hString is a handle to a valid string object
//Postcondition: Removes the last character in the string.
// Returns SUCCESS if the last character was successfully removed
// and FAILURE if the string was empty
Status string_pop_back(STRING hString);

//Precondition: none
//Postconditon: Clears the keyboard buffer and is ready for user input
void clear_keyboard_buffer(void);

//Precondition: hString is the handle to a valid String_Ptr object.
//Postcondition: Returns the addressof the character located at the given
// index if the index is in bounds but otherwise returns NULL. This address
// is not usable as a c-string since the data is not NULL terminatedand is
// intended to just provide access to the element at that index.
char* string_at(STRING hString, int index);

//Precondition: hString is the handle to a valid String_Ptr object.
//Postcondition: Returns the address of the first element of the string object
// for use as a c-string. The resulting c-string is guaranteed to be NULL
// terminated and the memory is still maintained by the string object though
// the NULL is not actually counted as part of the string (in size).
char* string_c_str(STRING hString);

//Precondition: hResult and hAppend are handles to valid String objects.
//Postcondition: hResult is the handle of a string that contains the original
// hResult object followed by the hAppend object concatenated together. This
// function should guarantee nochange to the hAppend object and return
// SUCCESS if the operation is successful and FAILURE if the hResult object
// is unable to accomodate the characters in thehAppend string perhaps
// because of a failed resize operation. On FAILURE, no change to either
// string should be made.
Status string_concat(STRING hResult, STRING hAppend);

//Precondition: hString is the handle to a valid String object.
//Postcondition: Returns an enumerated type with value TRUE if the string
// is empty and FALSE otherwise.
Boolean string_empty(STRING hString);

#endif //STRING_H_