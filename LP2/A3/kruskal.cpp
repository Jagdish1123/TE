#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

// Find the root of a node (Path compression)
int findParent(vector<int> &parent, int node)
{
    if (parent[node] != node)
        parent[node] = findParent(parent, parent[node]);
    return parent[node];
}

// Attach one node to another
void simpleUnion(vector<int> &parent, int u, int v)
{
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);
    parent[rootU] = rootV;
}

// Kruskal's Algorithm to find MST
void kruskalMST(vector<Edge> &edges, int V)
{
    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.weight < b.weight; });

    vector<int> parent(V);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<Edge> mst;

    // Process edges
    for (Edge &e : edges)
    {
        if (findParent(parent, e.src) != findParent(parent, e.dest))
        {
            mst.push_back(e);
            simpleUnion(parent, e.src, e.dest);
        }
    }

    // Output MST edges in desired format
    cout << "\nMinimum Spanning Tree (MST) Path:\n";
    for (Edge &e : mst)
    {
        cout << e.src << " --(" << e.weight << ")-- " << e.dest << endl;
    }
}

int main()
{
    vector<Edge> edges = {
        {0, 1, 2}, {0, 2, 3}, {1, 2, 1}, {1, 3, 4}, {3, 4, 5}
    };
    int V = 5;

    kruskalMST(edges, V);
    return 0;
}
