#include <stdio.h>

#include "clib/cstring.h"

void cstring_test()
{
    int value = 123;

    cstring_t *cs = cstring_copy_construct("abc");
    cstring_append_front_str(cs, "-");
    cstring_append_back_format(cs, "d");
    cstring_append_front_format(cs, " %d", value);

    printf("str: %s\n", cstring_data(cs));

    cstring_destroy(cs);
}
