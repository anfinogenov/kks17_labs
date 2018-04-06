#include <stdio.h>
#include <stdlib.h>
#include "../headers/single_list.h"

#define NULLPTR_ERR 1
#define UNKNOWN_ERR 101

List* new_list (int value) {
    List* new = (List*)malloc(sizeof(List));
    if (new == NULL) {
        return NULL;
    }
    new->value = value;
    new->next = NULL;
    return new;
}

List* push (List** head, int value) {
    List* temp = (List*)malloc(sizeof(List));
    if (temp == NULL) return NULL;
    temp->next = *head;
    temp->value = value;
    *head = temp;
    return *head;
}

int pop (List** head, int* flag) {
    if (*head == NULL) {
        *flag = NULLPTR_ERR;
        return -1;
    }
    List* temp = *head;
    int value = temp->value;
    *head = (*head)->next;
    free(temp);
    return value;
}

int peek (List* data, int* flag) {
    if (data != NULL)
        return data->value;

    *flag = NULLPTR_ERR;
    return -1;
}

void stack_ptr_demo () {
    puts("> Stack demonstration func.");

    List* data = new_list(0);
    if (data != NULL)
        puts("Created new list with initial value of 0");
    else {
        puts("Stack creation failed!");
        return;
    }

    for (int i = 1; i < 5; i++) {
        if (push(&data, i) != NULL) printf("Pushed: %d\n", i);
        else printf("Push returned NULL!\n");
    }

    int iserror = 0;
    for (int i = 0; i < 3; i++) {
        int result = pop(&data, &iserror);
        if (!iserror) printf("Pop: got %d\n", result);
        else printf("Got underflow!");
    }

    for (int i = 6; i < 11; i++) {
        if (push(&data, i) != NULL) printf("Pushed: %d\n", i);
        else printf("Push returned NULL!\n");
    }

    iserror = 0;
    for (int i = 1; i < 15; i++) {
        int result = pop(&data, &iserror);
        if (!iserror) printf("Pop: got %d\n", result);
        else printf("Got underflow!\n");
    }
}

int* new_array_list (int value) {
    int* array = (int*)malloc(3*sizeof(int));
    if (array == NULL) return NULL;
    array[0] = 1; //size
    array[1] = value;
    return array;
}

int* push_array (int** array, int value) {
    int size = ++(*array)[0];
    (*array)[size] = value;
    *array = (int*)realloc(*array, (size+3)*sizeof(int));
    return *array;
}

int pop_array (int** array, int* flag) {
    if (array == NULL) {
        *flag = NULLPTR_ERR;
        return -1;
    }
    int size = (*array)[0];
    if (size <= 0) {
        *flag = UNKNOWN_ERR;
        return -1;
    }
    int returned = (*array)[size];
    (*array) = (int*)realloc(*array, (size+2)*sizeof(int));
    if (*array == NULL) {
        *flag = NULLPTR_ERR;
        return -1;
    }
    (*array)[0]--;
    return returned;
}

int peek_array (const int* array, int* flag) {
    if (array == NULL) {
        *flag = NULLPTR_ERR;
        return -1;
    }
    if (array[0] <= 0) {
        *flag = UNKNOWN_ERR;
        return -1;
    }
    return array[array[0]]; // array[0] - size of stack
}

void stack_array_demo () {
    puts("> Stack demo (array based).");

    int* stack = new_array_list(0);
    if (stack != NULL)
        puts("Created new list with initial value of 0");
    else {
        puts("Stack creation failed");
        return;
    }

    for (int i = 1; i < 5; i++) {
        if (push_array(&stack, i) != NULL)
            printf("Pushed: %d\n", i);
        else puts("Push failed");
    }

    int iserror = 0;
    for (int i = 0; i < 3; i++) {
        int result = pop_array(&stack, &iserror);
        if (!iserror) printf("Pop: got %d\n", result);
        else puts("Got underflow!");
    }

    for (int i = 6; i < 11; i++) {
        if (push_array(&stack, i) != NULL)
            printf("Pushed: %d\n", i);
        else puts("Push failed");
    }

    iserror = 0;
    for (int i = 1; i < 15; i++) {
        int result = pop_array(&stack, &iserror);
        if (!iserror) printf("Pop: got %d\n", result);
        else puts("Got underflow!");
    }
}
