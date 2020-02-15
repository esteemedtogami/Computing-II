#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"

int main(int argc, char* argv[])
{
    BIT_FLAGS hBit_flags = NULL; //declaring the handle
    
    hBit_flags = bit_flags_init_number_of_bits((32)); //initialization of the object
    if (hBit_flags == NULL)
    {
        printf("Something terrible happened!\n");
        exit(1);
    }
    
    printf("%d / %d\n", bit_flags_get_size(hBit_flags), bit_flags_get_capacity(hBit_flags));
    
    bit_flags_set_flag(hBit_flags, 3);
    bit_flags_set_flag(hBit_flags, 16);
    bit_flags_set_flag(hBit_flags, 31);
    bit_flags_set_flag(hBit_flags, 87);
    //bit_flags_display_flags(hBit_flags, 5); good function to have
    printf("%d\n", bit_flags_check_flag(hBit_flags, 3));
    printf("%d\n", bit_flags_check_flag(hBit_flags, 17));
    printf("%d\n", bit_flags_check_flag(hBit_flags, 31));
    printf("%d\n", bit_flags_check_flag(hBit_flags, 87));
    printf("\n\n");
    bit_flags_unset_flag(hBit_flags, 31);
    bit_flags_unset_flag(hBit_flags, 3);
    bit_flags_set_flag(hBit_flags, 99);
    bit_flags_set_flag(hBit_flags, 100);
    //display_flags(flag_holder, 5); good function to have
    printf("%d\n", bit_flags_check_flag(hBit_flags, 3));
    printf("%d\n", bit_flags_check_flag(hBit_flags, 17));
    printf("%d\n", bit_flags_check_flag(hBit_flags, 99));
    printf("%d\n", bit_flags_check_flag(hBit_flags, 100));
    printf("\n\n");
    
    printf("%d / %d\n", bit_flags_get_size(hBit_flags), bit_flags_get_capacity(hBit_flags));
    
    
    
    
    
    
    bit_flags_destroy(&hBit_flags);

    
    return 0;
}
