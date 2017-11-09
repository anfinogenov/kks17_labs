#include <stdio.h>
#include <stdlib.h>
#include "../headers/single_list.h"

List* new_list (int value) {
    List* new = (List*)malloc(sizeof(List));
    new->value = value;
    new->next = NULL;
    return new;
}

void push (List** head, int value) {
    List* temp = (List*)malloc(sizeof(List));
    temp->next = *head;
    temp->value = value;
    *head = temp;
}

int pop (List** head) {
    if (*head == NULL) {
        fprintf(stderr, "err: stack underflow\n");
        exit(-1);
    }
    List* temp = *head;
    int value = temp->value;
    *head = (*head)->next;
    free(temp);
    return value;
}

int peek (List* data) {
    return data->value;
}

void stack_ptr_demo () {
    puts("> Stack demonstration func.");
    List* data = new_list(0);
    puts("Created new list with initial value of 0");
    for (int i = 1; i < 5; i++) {
        push(&data, i);
        printf("Pushed: %d\n", i);
    }

    for (int i = 0; i < 3; i++) {
        printf("Pop: got %d\n", pop(&data));
    }

    for (int i = 6; i < 11; i++) {
        push(&data, i);
        printf("Pushed: %d\n", i);
    }

    for (int i = 1; i < 15; i++) {
        printf("Pop: got %d\n", pop(&data));
    }
}

int* new_array_list (int value) {
    int* array = (int*)malloc(3*sizeof(int));
    array[0] = 1; //size
    array[1] = value;
    return array;
}

void push_array (int** array, int value) {
    int size = ++(*array)[0];
    (*array)[size] = value;
    *array = (int*)realloc(*array, (size+3)*sizeof(int));
}

int pop_array (int** array) {
    int size = (*array)[0];
    if (size == 0) {
        //fprintf(stderr, "err: stack underflow\n");
        exit(-1);
    }
    int returned = (*array)[size];
    (*array) = (int*)realloc(*array, (size+2)*sizeof(int));
    (*array)[0]--;
    return returned;
}

int peek_array (const int* array) {
    return array[array[0]];
}

void stack_array_demo () {
    puts("> Stack demo (array based).");
    int size = 0;
    int* stack = new_array_list(0);
    puts("Created new list with initial value of 0");
    
    for (int i = 1; i < 5; i++) {
        push_array(&stack, i);
        printf("Pushed: %d\n", i);
    }

    for (int i = 0; i < 3; i++) {
        printf("Pop: got %d\n", pop_array(&stack));
    }

    for (int i = 6; i < 11; i++) {
        push_array(&stack, i);
        printf("Pushed: %d\n", i);
    }

    for (int i = 1; i < 15; i++) {
        printf("Pop: got %d\n", pop_array(&stack));
    }
}
