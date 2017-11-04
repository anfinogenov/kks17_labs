#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

typedef struct List {
    int value;
    struct List* next;
} List;

List* new_list (int value);
void push (List** head, int value);
int pop (List** head);
int peek (List* data);
void stack_demo(void);

#endif
