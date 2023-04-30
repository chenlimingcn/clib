#include <stdio.h>

#include "clib/string/cstring.h"

int main(int argc ,char* argv[])
{
    cstring_t *cs = cstring_copy_construct("abc");

    printf("str: %s\n", cstring_data(cs));

    cstring_destroy(cs);
    
    return 0;
}