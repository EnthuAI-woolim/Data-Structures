// Unweighted graph
struct Queue {};

struct Graph {
    int V;
};

void UnweightedShortestPath(struct Graph *G, int s) {
    struct Queue *Q = CreateQueue();
    int v, w;
    EnQueue(Q, s);
    for (int i =0; i < G->V; i++) Distance[i] = -1;
    Distance[s] = 0;
    while (!IsEmptyQueue(Q)) {
        v = DeQueue(Q);
        for (/* v에 인접한 모든 정점 w에 대해 */) { // 각 정점은 최대 한 번 검사된다
            if (Distance[w] == -1) {
                Distance[w] = Distance[v] + 1;
                Path[w] = v;
                EnQueue(Q, w); // 각 정점은 최대 한 번 EnQueue된다
            }
        }
    }
    DeleteQueue(Q);
}

struct Queue* CreateQueue() {}

void EnQueue(struct Queue *Q, int s) {}

int DeQueue(struct Queue *Q) {}

int IsEmptyQueue(struct Queue *Q) {}

void DeleteQueue(struct Queue *Q) {}


// Weighted graph(Dijkstra algorithm)
struct PrioriyQueue {};

void Dijkstra(struct Graph *G, int s) {
    struct PrioriyQueue *PQ = CreatePriortyQueue();
    int v, w, d;
    EnQueue1(PQ, s);
    for (int i = 0; i < G->V; i++) Distance[i] = -1;
    Distance[s] = 0;
    while (!IsEmptyQueue1) {
        v = DeleteMin(PQ);
        for (/* v의 모든 인접한 정점 w에 대해 */) {
            d = Distance[v] + weight[v][w]; // 새로운 거리 계산
            if (Distance[w] == -1) {
                Distance[w] = d; // 새로운 거리
                Insert(PQ, w, d); // w를 우선순위 d로 우선순위 큐에 넣는다
                Path[w] = v;
            } else if (Distance[w] > d) {
                Distance[w] = d; // 새로운 거리
                Update(PQ, w, d); // w의 우선순위가 d가 되도록 업데이트
                Path[w] = v;
            }
        }
    }
}

struct PrioriyQueue* CreatePriortyQueue() {}

void EnQueue1(struct PrioriyQueue *PQ, int s) {}

int IsEmptyQueue1(struct PrioriyQueue *PQ) {}

int DeleteMin(struct PrioriyQueue *PQ) {}

void Insert(struct PrioriyQueue *PQ, int w, int d) {}

void Update(struct PrioriyQueue *PQ, int w, int d) {}