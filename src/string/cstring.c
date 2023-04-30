#include "clib/string/cstring.h"

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct cstring
{
    char*  data;
    size_t capacity;
    size_t length;
};

#define CSTRING_MIN_CAPACITY 64

cstring_t *cstring_construct()
{
    cstring_t *cs = (cstring_t*)malloc(sizeof(cstring_t));
    cs->capacity = CSTRING_MIN_CAPACITY;
    cs->data = (char*)malloc(CSTRING_MIN_CAPACITY);
    cs->length = 0;
    cs->data[0] = '\0';

    return cs;
}

cstring_t* cstring_copy_construct(const char* str)
{
    size_t len = strlen(str);
    size_t size = len + 1;

    cstring_t *cs = (cstring_t*)malloc(sizeof(cstring_t));
    cs->capacity = CSTRING_MIN_CAPACITY;
    while (size > cs->capacity)
    {
        cs->capacity = cs->capacity * 2;
    }
    cs->data = (char*)malloc(cs->capacity);
    // TODO: overlap
    memcpy(cs->data, str, len);
    cs->length = len;
    cs->data[len] = '\0';

    return cs;
}

void cstring_destroy(cstring_t *cs)
{
    free(cs->data);
    free(cs);
}

cstring_t *cstring_append_front_str(cstring_t *cs, const char *str)
{
    size_t str_len = strlen(str);
    size_t len = cs->length + str_len;
    size_t size = len + 1;

    size_t capacity = cs->capacity;
    while (size > capacity)
    {
        capacity = capacity * 2;
    }

    if (capacity != cs->capacity)
    {
        char* data = (char*)malloc(capacity);

        memcpy(data, str, str_len);
        memcpy(data + str_len, cs->data, cs->length);

        cs->capacity = capacity;
        free(cs->data);
        cs->data = data;
    }
    else
    {
        memmove(cs->data + str_len, cs->data, cs->length);
        memcpy(cs->data, str, str_len);
    }


    cs->length = len;
    cs->data[len] = '\0';

    return cs;
}

cstring_t *cstring_append_front_char(cstring_t *cs, char c)
{
    size_t len = cs->length + 1;
    size_t size = len + 1;

    size_t capacity = cs->capacity;
    while (size > capacity)
    {
        capacity = capacity * 2;
    }
    
    if (capacity != cs->capacity)
    {
        char* data = (char*)malloc(cs->capacity);
        data[0] = c;
        memcpy(data + 1, cs->data, cs->length);

        cs->capacity = capacity;
        free(cs->data);
        cs->data = data;
    }
    else
    {
        memmove(cs->data + 1, cs->data, cs->length);
        cs->data[0] = c;
    }

    cs->length = len;
    cs->data[len] = '\0';

    return cs;
}

cstring_t* cstring_append_front_format(cstring_t* cs, const char* format, ...)
{
    va_list arg;

    va_start(arg, format);

    size_t str_len = vsnprintf(NULL, 0, format, arg);
    size_t len = str_len + cs->length;
    size_t size = len + 1;

    size_t capacity = cs->capacity;
    while (size > capacity)
    {
        capacity = capacity * 2;
    }

    char* data = (char*)malloc(cs->capacity);

    size_t tmp_len = vsprintf(data, format, arg);
    strcpy(data + tmp_len, cs->data);
    free(cs->data);
    cs->data = data;

    cs->length = len;
    cs->data[len] = '\0';

    va_end(arg);

    return cs;
}

cstring_t *cstring_append_back_str(cstring_t *cs, const char *str)
{
    size_t str_len = strlen(str);
    size_t len = cs->length + str_len;
    size_t size = len + 1;

    size_t capacity = cs->capacity;
    while (size > capacity)
    {
        capacity = capacity * 2;
    }
    
    if (capacity != cs->capacity)
    {
        char* data = (char*)malloc(cs->capacity);
        memcpy(data, cs->data, cs->length);
        cs->capacity = capacity;
        cs->data = data;
    }

    memcpy(cs->data + cs->length, str, str_len);
    cs->length = len;
    cs->data[len] = '\0';

    return cs;
}

cstring_t *cstring_append_back_char(cstring_t *cs, char c)
{
    size_t len = cs->length + 1;
    size_t size = len + 1;

    size_t capacity = cs->capacity;
    while (size > capacity)
    {
        capacity = capacity * 2;
    }
    
    if (capacity != cs->capacity)
    {
        char *data = (char*)malloc(capacity);
        memcpy(data, cs->data, cs->length);
        cs->capacity = capacity;
        cs->data = data;
    }
    cs->data[cs->length] = c;
    cs->length = len;
    cs->data[len] = '\0';

    return cs;
}

cstring_t* cstring_append_back_format(cstring_t* cs, const char* format, ...)
{
    va_list arg;

    va_start(arg, format);

    size_t str_len = vsnprintf(NULL, 0, format, arg);
    size_t len = str_len + cs->length;
    size_t size = len + 1;

    size_t capacity = cs->capacity;
    while (size > capacity)
    {
        capacity = capacity * 2;
    }

    if (capacity != cs->capacity)
    {
        char *data = (char*)malloc(capacity);
        memcpy(data, cs->data, cs->length);
        cs->capacity = capacity;
        cs->data = data;
    }

    vsprintf(cs->data, format, arg);
    cs->length = len;
    cs->data[len] = '\0';

    va_end(arg);

    return cs;
}

cstring_t* cstring_clear(cstring_t* cs)
{
    cs->length = 0;
    cs->data[0] = '\0';

    return cs;
}

cstring_t* cstring_drop_front(cstring_t* cs, size_t len)
{
    if (cs->length < len)
    {
        cs->data[0] = '\0';
        cs->length = 0;
    }
    else
    {
        memcpy(cs->data, cs->data + len, cs->length - len);
        cs->length -= len;
        cs->data[cs->length] = '\0';
    }

    return cs;
}

cstring_t* cstring_drop_back(cstring_t* cs, size_t len)
{
    if (cs->length < len)
    {
        cs->data[0] = '\0';
        cs->length = 0;
    }
    else
    {
        cs->length -= len;
        cs->data[cs->length] = '\0';
    }

    return cs;
}

size_t cstring_length(cstring_t* cs)
{
    return cs->length;
}

const char *cstring_data(cstring_t *cs)
{
    return cs->data;
}

char* cstring_data_dump(const cstring_t* cs)
{
    char *data = (char*)malloc(cs->length + 1);
    memcpy(data, cs->data, cs->length);
    data[cs->length] = '\0';

    return data;
}
