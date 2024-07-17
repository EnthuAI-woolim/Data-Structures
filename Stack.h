#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Linked List
struct Stack {
    int data;
    struct Stack *next;
};

struct Stack *CreateStack() {
    return NULL;
}

void Push(struct Stack **top, int data) {
    struct Stack *temp;
    temp = (struct Stack*)malloc(sizeof(struct Stack));
    if(!temp) return;
    
    temp->data = data;
    temp->next = *top;
    *top = temp;
}

int IsEmptyStack(struct Stack *top) {
    return top == NULL;
}

int Pop(struct Stack **top) {
    int data;
    struct Stack *temp;
    if (IsEmptyStack(*top)) return INT_MIN;

    temp = *top;
    *top = (*top)->next;
    data = temp->data;
    free(temp);
    return data;
}

int Top(struct Stack *top) {
    if (IsEmptyStack(top)) return INT_MIN;
    return top->data;
}

void DeleteStack(struct Stack **top) {
    struct Stack *temp, *p;
    p = *top;
    while (p) {
        temp = p->next;
        free(p);
        p = temp;
    }
    *top = NULL;
}
