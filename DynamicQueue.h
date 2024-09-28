struct DynArrayQueue {
    int front, rear;
    int capacity;
    int *array;
}

struct DynArrayQueue *CreateDynQueue() {
    struct DynArrayQueue *Q = malloc(sizeof(struct DynArrayQueue));
    if(!Q)
        return NULL;
    Q->capacity = 1;
    Q->front = Q->rear = -1;
    Q->array = malloc(Q->capacity * sizeof(int));
    if(!Q->array)
        return NULL;
    return Q;
}

int IsEmtpyQueue(struct ArrayQueue *Q) {
    // 조건이 참이면 1이 리턴되고 아니면 0이 리턴된다.
    return (Q->front == -1);
}

int IsFullQueue(struct ArrayQueue *Q) {
    // 조건이 참이면 1이 리턴되고 이니면 0이 리턴된다.
    return ((Q->rear+1) % Q->capacity == Q->front);
}

int QueueSize(struct ArrayQueue *Q) {
    return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}

void EnQueue(struct ArrayQueue *Q, int data) {
    if(IsFullQueue(Q))
        ResizeQueue(Q);

    Q->rear = (Q->rear+1) % Q->capacity;
    Q->array[Q->rear] = data;
    if(Q->front == -1)
        Q->front = Q->rear;
}

void ResizeQueue(struct DynArrayQueue *Q) {
    int size = Q->capacity;
    Q->capacity = Q->capacity*2;
    q->array = realloc(Q->array, Q->capacity);
    if(!Q->array) {
        printf("Memorry Error");
        return;
    }
    if(Q->front > Q->realloc) {
        for(int = 0;; i < Q->for; i++)
            Q->array[i+size] = Q->array[i];
        Q->realloc = Q->realloc + size;
    }
}

// 11 00:06:24