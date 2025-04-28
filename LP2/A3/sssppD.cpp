#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

void djikshtras(vector<Edge> &edges, int V, int src)
{
    //  edge list
    vector<vector<pair<int, int>>> adjList(V);
    for (const Edge &e : edges)
    {
        adjList[e.src].push_back({e.dest, e.weight});
        adjList[e.dest].push_back({e.src, e.weight});
    }

    // Dijkstra's algorithm
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    dist[src] = 0;

    pq.push({0, src});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        // Traverse the adjacent nodes
        for (auto i : adjList[u])
        {
            int v = i.first;
            int weight = i.second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Output the shortest path distances and the paths
    for (int i = 0; i < V; i++)
    {
        cout << "Shortest path from " << src << " to " << i << " is " << dist[i] << ". Path: ";

        vector<int> path;
        int current = i;
        while (current != -1)
        {
            path.push_back(current);
            current = parent[current];
        }

        reverse(path.begin(), path.end());
        for (int node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }
}

int main()
{
    // {src, dest, weight}
    vector<Edge> edges = {
        {0, 1, 2}, {0, 2, 3}, {1, 2, 1}, {1, 3, 4}, {3, 4, 5}};
    int V = 5;

    djikshtras(edges, V, 0);

    return 0;
}
