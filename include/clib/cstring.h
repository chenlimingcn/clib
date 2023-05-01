#ifndef CSTRING_H__
#define CSTRING_H__

#include <stddef.h>

struct cstring;
typedef struct cstring cstring_t;

cstring_t* cstring_construct();
cstring_t* cstring_copy_construct(const char* str);
void cstring_destroy(cstring_t* cs);

cstring_t* cstring_append_front_str(cstring_t* cs, const char* str);
cstring_t* cstring_append_front_char(cstring_t* cs, char c);
cstring_t* cstring_append_front_format(cstring_t* cs, const char* format, ...);

cstring_t* cstring_append_back_str(cstring_t* cs, const char* str);
cstring_t* cstring_append_back_char(cstring_t* cs, char c);
cstring_t* cstring_append_back_format(cstring_t* cs, const char* format, ...);

cstring_t* cstring_clear(cstring_t* cs);
cstring_t* cstring_drop_front(cstring_t* cs, size_t len);
cstring_t* cstring_drop_back(cstring_t* cs, size_t len);

size_t cstring_length(cstring_t* cs);
const char* cstring_data(cstring_t* cs);
char* cstring_data_dump(const cstring_t* cs);

// TODO: find/replace...

#endif//CSTRING_H__
