#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

typedef struct List {
    int value;
    struct List* next;
} List;

List* new_list (int value);
List* push (List** head, int value);
int pop (List** head, int* flag);
int peek (List* data, int* flag);

int* push_array (int** array, int value);
int pop_array (int** array, int* flag);
int peek_array (const int* array, int* flag);

void stack_ptr_demo(void);
void stack_array_demo(void);

#endif
