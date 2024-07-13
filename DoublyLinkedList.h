#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 이중 연결 리스트

struct DLLNode {
    int data;
    struct DLLNode *prev;
    struct DLLNode *next;
};

int DLLLength(struct DLLNode* head) {
    struct DLLNode *current = head;
    int count = 0;
    while(current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void DLLInsert(struct DLLNode **h, int data, int position) {
    int k = 1;
    struct DLLNode *temp, *newNode;
    newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    if (!newNode) { // 메모리 에러를 항상 확인한다.
        printf("Memory Eroor");
        return;
    }

    newNode->data = data;
    if (position == 1) { // 리스트 가장 앞에 노드를 삽입한다.
        newNode->next = *h;
        newNode->prev = NULL;
        if ((*h) != NULL) (*h)->prev = newNode; // 원래 코드 => // (*h)->prev = newNode;
        *h = newNode;
        return;
    }

    temp = *h;
    while (temp->next != NULL && (k < position)) {
        temp = temp->next;
        k++;
    }
    if (temp->next == NULL) { // 리스트 가장 끝에 노드를 삽입한다.
        newNode->prev = temp;
        newNode->next = NULL; // 원래 코드 => newNode->next = temp->next;
        temp->next = newNode;
    } else { // 리스트 중간에 노드를 삽입한다.
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    return;
}

void DLLDelete(struct DLLNode **h, int position) {
    struct DLLNode *temp1, *temp2;
    temp1 = *h;
    int k = 1;
    if (*h == NULL) {
        printf("List is empty");
        return;
    } 

    if (position == 1) {
        *h = (*h)->next;
        if (*h != NULL) (*h)->prev = NULL;
        free(temp1);
        return;
    }

    while ((temp1->next != NULL) && (k < position)) {
        temp1 = temp1->next;
        k++;
    }
    
    if (temp1->next == NULL) {
        temp2 = temp1->prev;
        temp2->next = NULL;
        free(temp1);
    } else {
        temp2 = temp1->prev;
        temp2->next = temp1->next;
        temp1->next->prev = temp2;
        free(temp1);
    }
    return;
}