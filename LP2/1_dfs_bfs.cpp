#include<bits/stdc++.h>
using namespace std;

// Add edge to undirected graph
void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

// Iterative BFS
void bfsIterative(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
// Iterative DFS
void dfsIterative(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int node = s.top(); s.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

// Recursive BFS helper
void bfsRecursiveHelper(queue<int>& q, const vector<vector<int>>& graph, vector<bool>& visited) {
    if (q.empty()) return;

    int node = q.front(); q.pop();
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }

    bfsRecursiveHelper(q, graph, visited);
}

// Recursive BFS
void bfsRecursive(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    bfsRecursiveHelper(q, graph, visited);
}



// Recursive DFS
void dfsRecursive(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsRecursive(neighbor, graph, visited);
        }
    }
}

int main() {
//     cout << "Enter number of vertices: ";
//     cin >> V;
//     cout << "Enter number of edges: ";
//     cin >> E;

//     vector<vector<int>> graph(V);

//     cout << "Enter " << E << " edges (format: u v):\n";
//     for (int i = 0; i < E; ++i) {
//         int u, v;
//         cin >> u >> v;
//         addEdge(graph, u, v);
//     }

    int V = 9;
    vector<vector<int>> graph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 8);
    addEdge(graph, 3, 5);
    addEdge(graph, 1, 6);
    addEdge(graph, 6, 7);

    vector<bool> vis1(V, false);
    cout << "BFS Iterative from 0: ";
    bfsIterative(0, graph, vis1);

    vector<bool> vis2(V, false);
    cout << "\nBFS Recursive from 0: ";
    bfsRecursive(0, graph, vis2);

    vector<bool> vis3(V, false);
    cout << "\nDFS Iterative from 0: ";
    dfsIterative(0, graph, vis3);

    vector<bool> vis4(V, false);
    cout << "\nDFS Recursive from 0: ";
    dfsRecursive(0, graph, vis4);

    return 0;
}


