
#include <bits/stdc++.h>
using namespace std;

void dfs_recursive(vector<vector<int>> &adj_matrix, int s, vector<bool> &visited)
{
    visited[s] = true;
    cout << s << " ";

    for (int neighbor : adj_matrix[s])
    {
        if (!visited[neighbor])
        {
            dfs_recursive(adj_matrix, neighbor, visited);
        }
    }
}

void bfs_recursive_helper(queue<int> &q, vector<vector<int>> &adj_matrix, vector<bool> &visited)
{
    if (q.empty())
        return;

    int current = q.front();
    q.pop();
    cout << current << " ";

    for (int neighbor : adj_matrix[current])
    {
        if (!visited[neighbor])
        {
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }

    bfs_recursive_helper(q, adj_matrix, visited);
}

void bfs_recursive(vector<vector<int>> &adj_matrix, int s, vector<bool> &visited)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);
    bfs_recursive_helper(q, adj_matrix, visited);
}

void dfs(vector<vector<int>> &adj_matrix, int s, vector<bool> &visited)
{
    stack<int> st;
    st.push(s);

    while (!st.empty())
    {
        int current = st.top();
        st.pop();

        if (!visited[current])
        {
            visited[current] = true;
            cout << current << " ";

            for (auto it = adj_matrix[current].rbegin(); it != adj_matrix[current].rend(); ++it)
            {
                if (!visited[*it])
                {
                    st.push(*it);
                }
            }
        }
    }
}

void bfs(vector<vector<int>> &adj_matrix, int s, vector<bool> &visited)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : adj_matrix[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void addEdge(vector<vector<int>> &adj_matrix, int u, int v)
{
    adj_matrix[u].push_back(v);
    adj_matrix[v].push_back(u);
}

int main()
{
    int V = 9;
    vector<vector<int>> adj_matrix(V);

    addEdge(adj_matrix, 0, 2);
    addEdge(adj_matrix, 2, 4);
    addEdge(adj_matrix, 0, 1);
    addEdge(adj_matrix, 0, 3);
    addEdge(adj_matrix, 3, 5);
    addEdge(adj_matrix, 1, 6);
    addEdge(adj_matrix, 6, 7);
    addEdge(adj_matrix, 2, 8);

    cout << "\nBFS starting from 0 : \n";
    vector<bool> visited_b(V, false);
    bfs(adj_matrix, 0, visited_b);

    cout << "\nRecursive-BFS starting from 0 : \n";
    vector<bool> visited_bfs(V, false);
    bfs_recursive(adj_matrix, 0, visited_bfs);

    cout << "\nDFS starting from 0 : \n";
    vector<bool> visited_d(V, false);
    dfs(adj_matrix, 0, visited_d);

    cout << "\nRecursive-DFS starting from 0 : \n";
    vector<bool> visited_dfs(V, false);
    dfs_recursive(adj_matrix, 0, visited_dfs);

    return 0;
}

    //        0
    //     2  1  3
    //   4  8 6    5
    //        7