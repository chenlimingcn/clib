#include <stdio.h>

extern void cstring_test();
extern void rqueue_test();


int main(int argc, char* argv[])
{
    cstring_test();
    rqueue_test();
    
    return 0;
}