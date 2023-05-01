#include "clib/linklist.h"

#include <stdio.h>

void print_int(int value)
{
    printf("%d\n", value);
}

void linklist_test()
{
    int value = 1;

    linklist_t *head = linklist_create(value);
    head = linklist_push_front(head, --value);
    
    linklist_print(head, print_int);

    linklist_free(head, NULL);

    head = linklist_create(value);
    head = linklist_push_back(head, ++value);
    head = linklist_push_back(head, ++value);

    linklist_print(head, print_int);
}