// 01269번 DFS와 BFS
#include <stdio.h>
#include <vector>
#include <set>
#include <stack>
#include <queue>

using namespace std;

void dfs(set<short> *graph, short N, short V);
void bfs(set<short> *graph, short N, short V);

int main() {
    short N, M, V;
    short current, from, to;
    short i;
    set<short> *graph;

    // Scan
    scanf("%hd %hd %hd", &N, &M, &V);
    graph = new set<short>[N];


    // Make bidirectional adjacent list
    for(i=0; i<M; i++) {
        scanf("%hd %hd", &from, &to);
        graph[from - 1].insert(to - 1);
        graph[to - 1].insert(from - 1);
    }

    dfs(graph, N, V);
    bfs(graph, N, V);

    return 0;
}

void dfs(set<short> *graph, short N, short V) {
    short current;
    short i;
    set<short>::iterator iter;
    vector<bool> *visited;
    stack<short> dfs_stack;
    bool search_deeper;

    // Initialize visited set and dfs stack
    visited = new vector<bool>(N);
    for(i=0; i<N; i++) {
        visited->at(i) = false;
    }
    dfs_stack.push(V - 1);

    // DFS loop    
    while (!dfs_stack.empty()) {
        current = dfs_stack.top();
        
        if (!visited->at(current)) {
            visited->at(current) = true;
            printf("%d ", current + 1);
        }

        search_deeper = false;
        for (iter=graph[current].begin(); iter!=graph[current].end(); iter++) {
            if (!visited->at(*iter)) {
                dfs_stack.push(*iter);
                search_deeper = true;
                break;
            }
        }
        
        if (!search_deeper) {
            dfs_stack.pop();
        }
    }
    printf("\n");
}

void bfs(set<short> *graph, short N, short V) {
    short current, i;
    set<short>::iterator iter;
    vector<bool> *visited;
    queue<short> bfs_queue;

    // Initialize visited set and bfs queue
    visited = new vector<bool>(N);
    for(i=0; i<N; i++) {
        visited->at(i) = false;
    }
    bfs_queue.push(V - 1);

    // BFS loop
    while (!bfs_queue.empty()) {
        current = bfs_queue.front();
        bfs_queue.pop();

        if (!visited->at(current)) {
            visited->at(current) = true;
            printf("%d ", current + 1);
        }

        for (iter=graph[current].begin(); iter!=graph[current].end(); iter++) {
            // printf("check %hd: %s\n", *iter, visited->at(*iter) ? "true" : "false");
            if (!visited->at(*iter)) {
                bfs_queue.push(*iter);
            }
        }
    }
    printf("\n");
}