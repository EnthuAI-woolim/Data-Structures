// Kruskal Algorithm / O(ElogE)
struct Graph {
    int V;
};

int kruskal(struct Graph *G) {
    S = /*공집합*/; // 맨 마지막에 S에는 minimum spanning tree의 edge들이 저장된다
    for (int v = 0; v < G->V; v++) {
        MakeSet(v);
    }
    /* E의 간선들을 가중치 w가 증가하는 순서로 정렬한다; */
    for (/* E안의 모든 간선 (u, v)에 대해 */) { // 정렬된 리스트로부터
        if(FIND(u) != FIND(v)) {
            S = S /*합집합*/ {(u, v)};
            UNION(u, v);
        }
    }
    return S;
}

void MakeSet(int v) {}

int FIND(int u) {}

void UNION(int u, int v) {}


// Prim Algorithm
struct PrioriyQueue {};

void Prim(struct Graph *G, int s) {
    struct PrioriyQueue *PQ = CreatePriortyQueue();
    int v, w;
    EnQueue(PQ, s);
    for (int i = 0; i < G->V; i++) Distance[i] = -1; // distance table 기본값을 -1로 설정
    Distance[s] = 0; 
    while (!IsEmptyQueue{PQ}) {
        v = DeleteMin(PQ);
        for (/* v의 모든 인접한 정점 w에 대해 */) {
            d = weight[v][w]; // 새로운 거리 계산
            if (Distance[w] == -1) {
                Distance[w] = Distance[v][w];
                Insert(PQ, w, d); // w를 priority queue에 넣는다
                Path[w] = v;
            }
            if (Distance[w] > d) {
                Distance[w] = weight[v][w];
                Update(PQ, w, d); // 정점 w의 우선순위가 d가 되도록 한다
                Path[w] = v;
            }
        }
    }
}

struct PrioriyQueue* CreatePriortyQueue() {}

void EnQueue(struct PrioriyQueue *PQ, int s) {}

int IsEmptyQueue(struct PrioriyQueue *PQ) {}

int DeleteMin(struct PrioriyQueue *PQ) {}

void Insert(struct PrioriyQueue *PQ, int w, int d) {}

void Update(struct PrioriyQueue *PQ, int w, int d) {}