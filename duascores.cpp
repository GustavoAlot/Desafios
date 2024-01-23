#include <iostream>
#include <cstdlib> 

using namespace std;

const int MAX_N = 200; 

struct Queue {
    int *items;
    int front, rear, size, capacity;

    Queue(int capacity) {
        this->capacity = capacity;
        items = new int[capacity];
        front = size = 0;
        rear = capacity - 1;
    }

    ~Queue() {
        delete[] items;
    }

    bool isFull() { return (size == capacity); }

    bool isEmpty() { return (size == 0); }

    void enqueue(int item) {
        if (isFull()) return;
        rear = (rear + 1) % capacity;
        items[rear] = item;
        size++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int item = items[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }
};

bool bicolorable(int graph[MAX_N][MAX_N], int n) {
    int *color = new int[n];
    for (int i = 0; i < n; ++i) color[i] = -1;

    for (int start = 0; start < n; ++start) {
        if (color[start] == -1) {
            Queue q(n);
            q.enqueue(start);
            color[start] = 0;
            
            while (!q.isEmpty()) {
                int u = q.dequeue();
                
                for (int v = 0; v < n; ++v) {
                    if (graph[u][v] != 0) { // Se v e vizinho de u
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.enqueue(v);
                        } else if (color[v] == color[u]) {
                            delete[] color;
                            return false;
                        }
                    }
                }
            }
        }
    }
    
    delete[] color;
    return true;
}

int main() {
    int n, l;
    int graph[MAX_N][MAX_N];
    
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                graph[i][j] = 0;

        cin >> l;
        for (int i = 0; i < l; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u][v] = graph[v][u] = 1;
        }
        
        if (bicolorable(graph, n)) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }
    return 0;
}
