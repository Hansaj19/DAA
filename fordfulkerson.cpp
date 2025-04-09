#include <iostream>
#include <vector>
using namespace std;
#define v 4

bool dfs(int rGraph[v][v], int s, int t, bool visited[], int parent[]) {
    visited[s] = true;
    if (s == t) return true;

    for (int i = 0; i < v; i++) {
        if (!visited[i] && rGraph[s][i] > 0) {
            parent[i] = s;
            if (dfs(rGraph, i, t, visited, parent)) return true;
        }
    }
    return false;
}

int ford(int graph[v][v], int s, int t) {
    int rGraph[v][v];
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            rGraph[i][j] = graph[i][j];

    int parent[v];
    int maxF = 0;

    while (true) {
        bool visited[v] = {false};
        if (!dfs(rGraph, s, t, visited, parent)) break;

        int path_flo = INT_MAX;
        for (int i = t; i != s; i = parent[i])
            path_flo = min(path_flo, rGraph[parent[i]][i]);

        for (int i = t; i != s; i = parent[i]) {
            int j = parent[i];
            rGraph[j][i] -= path_flo;
            rGraph[i][j] += path_flo;
        }

        maxF += path_flo;
    }
    return maxF;
}

int main() {
    int graph[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> graph[i][j];

    cout << "The maximum possible flow is " << ford(graph, 0, 3);
    return 0;
}
