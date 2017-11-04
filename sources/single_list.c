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

void stack_demo () {
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
