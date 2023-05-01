#ifndef LINKLIST_H__
#define LINKLIST_H__

typedef int linklist_value_t;

typedef void (*print_callback_t)(linklist_value_t value);
typedef void (*free_callback_t)(linklist_value_t value);

struct linklist;
typedef struct linklist linklist_t;

linklist_t* linklist_create(linklist_value_t value);
void linklist_free(linklist_t *head, free_callback_t callback);

linklist_t* linklist_push_front(linklist_t *head, linklist_value_t value);
linklist_t* linklist_push_back(linklist_t *head, linklist_value_t value);

linklist_t* linklist_pop_front(linklist_t *head, linklist_value_t* pvalue);
linklist_t* linklist_pop_back(linklist_t *head, linklist_value_t* pvalue);

void linklist_print(linklist_t* head, print_callback_t callback);

#endif//LINKLIST_H__
