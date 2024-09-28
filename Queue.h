struct ArrayQueue {
    int front, rear;
    int capacity;
    int *array;
}

struct ArrayQueue *Queue(int size) {
    struct ArrayQueue *Q = malloc(sizeof(struct ArrayQueue));
    if (!Q)
        return NULL;
    Q->capacity = size;
    Q->front = Q->rear = -1;
    Q->array = malloc(Q->capacity * sizeof(int));
    if (!Q->array)
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
        printf("Queue Overflow");
    else {
        Q->rear = (Q->rear+1) % Q->capacity;
        Q->array[Q->rear] = data;
        if(Q->front == -1)
            Q->front = Q->rear;
    }
}

int DeQueue(struct ArrayQueue *Q) {
    int data = 0; // 또는 큐에 존재하지 않는 항목
    if(IsEmtpyQueue(Q)) {
        printf("Queue is Empty");
        return 0;
    }
    else {
        data = Q->array[Q->front];
        if(Q->front == Q->rear)
            Q->front = Q->rear = -1;
        else
            Q->front = (Q->front+1) % Q->capacity;
    }
    return data;
}

void DeleteQueue(struct ArrayQueue *Q) {
    if(Q)
        free(Q->array);
    free(Q);
}