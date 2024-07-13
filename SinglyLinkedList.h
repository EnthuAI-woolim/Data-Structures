#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 단일 연결 리스트

struct ListNode {
    int data;
    struct ListNode *next;
};

int ListLength(struct ListNode* head) {
    struct ListNode *current = head;
    int count = 0;
    while(current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void InsertInLinkedList(struct ListNode **h, int data, int position) {
    int k = 1;
    struct ListNode *p, *q, *newNode;
    newNode = (ListNode*)malloc(sizeof(struct ListNode));
    if (!newNode) { // 항상 메모리 에러를 확인해야 한다.
        printf("Memory Error");
        return;
    }

    newNode->data = data;
    p = *h;
    if (position == 1) { // 가장 처음에 노드를 추가한다.
        newNode->next = p;
        *h = newNode;
    } else { // position까지 진행한다.
        while((p != NULL) && (k < position)) {
            k++;
            q = p;
            p = p->next;
        }
        if (p == NULL) { // 가장 끝에 노드를 추가한다.
            q->next = newNode;
            newNode->next = NULL;
        } else { // 중간에 노드를 추가한다.
            q->next = newNode;
            newNode->next = p;
        }
    }
    return;
}

void DeleteNodeFromLinkedList(struct ListNode **h, int position) {
    int k = 1;
    struct ListNode *p, *q;
    if (*h == NULL) {
        printf("List Empty");
        return;
    }

    p = *h;
    if (position == 1) { // 리스트 가장 앞에서 삭제
        *h = (*h)->next;
        free(p);
    } else { // 삭제할 위치까지 리스트 탐색하기
        while((p != NULL) && (k < position)){
            k++;
            q = p;
            p = p->next;
        }
        if (p == NULL) { // 리스트에 없는 항목의 경우
            printf("Position does not exist.");
        } else { // 리스트 중간 또는 맨끝을 삭제하는 경우
            q->next = p->next;
            free(p);
        }
    }
    return;
}

void DeleteLinkedList(struct ListNode **h) {
    struct ListNode *auxilaryNode, *iterator;
    iterator = *h;
    while (iterator) {
        auxilaryNode = iterator->next;
        free(iterator);
        iterator = auxilaryNode;
    }
    *h = NULL; // 호출한 함수의 진짜 '헤드' 노드 포인터에 영향을 주기 위해
    return;
}