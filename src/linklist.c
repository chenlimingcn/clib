#include "clib/linklist.h"

#include <stdlib.h>

struct linklist
{
    linklist_value_t value;
    struct linklist* next;
};

linklist_t* linklist_create(linklist_value_t value)
{
    linklist_t *head = (linklist_t*)malloc(sizeof(linklist_t));
    head->value = value;
    head->next = NULL;

    return head;
}

void linklist_free(linklist_t *head, free_callback_t callback)
{
    linklist_t *node = head;
    linklist_t *tmp = head;
    while (node)
    {
        tmp = node;
        node = node->next;
        if (callback)
        {
            callback(tmp->value);
        }
        free(tmp);
    }
}

linklist_t* linklist_push_front(linklist_t *head, linklist_value_t value)
{
    linklist_t *node = (linklist_t*)malloc(sizeof(linklist_t));
    node->value = value;
    node->next = head;

    return node;
}

linklist_t* linklist_push_back(linklist_t *head, linklist_value_t value)
{
    linklist_t *node = (linklist_t*)malloc(sizeof(linklist_t));
    node->value = value;
    node->next = NULL;

    linklist_t *tmp = head;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = node;

    return head;
}

linklist_t* linklist_pop_front(linklist_t *head, linklist_value_t* pvalue)
{
    linklist_t *tmp = head;
    *pvalue = tmp->value;

    head = tmp->next;

    free(tmp);
    return head;
}

linklist_t* linklist_pop_back(linklist_t *head, linklist_value_t* pvalue)
{
    linklist_t *pre = head;
    linklist_t *cur = head->next;
    if (!cur)
    {
        *pvalue = head->value;
        free(head);
        return NULL;
    }
    while (cur->next)
    {
        pre = cur;
        cur = pre->next;
    }

    *pvalue = cur->value;
    free(cur);
    pre->next = NULL;

    return head;
}

void linklist_print(linklist_t* head, print_callback_t callback)
{
    linklist_t *tmp = head;
  
    while (tmp)
    {
        if (callback)
        {
            callback(tmp->value);
        }
        tmp = tmp->next;
    }
}

