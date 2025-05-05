#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int x, y;
    int f, g, h;
    bool obstacle;
    bool visited;

    Node *parent;

    Node(int x, int y, bool obstacle = false) : x(x), y(y), obstacle(obstacle), visited(false), parent(nullptr) {}

    bool isObstacle() const { return obstacle; }
};

// calculate the heuristic
int heuristic(Node *start, Node *end)
{
    return abs(start->x - end->x) + abs(start->y - end->y);
}

// A* algorithm
vector<Node *> aStar(vector<vector<Node>> &grid, Node *start, Node *end)
{

    // Define a comparator for Node*
    struct CompareNodes
    {
        bool operator()(Node *a, Node *b)
        {
            return a->f > b->f; // Min-heap based on 'f'
        }
    };

    // Use the comparator in the priority queue
    priority_queue<Node *, vector<Node *>, CompareNodes> nodesToVisit;

    set<Node *> openSet;


    start->g = 0;
    start->h = heuristic(start, end);
    start->f = start->g + start->h;

    nodesToVisit.push(start);
    openSet.insert(start);

    while (!nodesToVisit.empty())
    {
        // Getting the node with the lowest f value i.e with highest priority in the Q

        Node *current = nodesToVisit.top();
        nodesToVisit.pop();

        // If this node is the end node i.e we reach the destination
        if (current == end)
        {
            vector<Node *> path;

            while (current != nullptr)
            {
                path.push_back(current);
                current = current->parent;
            }

            reverse(path.begin(), path.end());
            return path;
        }

        // Mark the node as visited
        current->visited = true;

        // Generate children
        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                // Skip the parent node or itself
                if (dx == 0 && dy == 0)
                    continue;

                // Get child position
                int x = current->x + dx;
                int y = current->y + dy;

                // Check if the position is valid
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
                {
                    Node *child = &grid[x][y];

                    // Only process the child if it's not an obstacle and not visited
                    if (!child->isObstacle() && !child->visited)
                    {
                        // Calculate g, h, and f values
                        int g = current->g + 1;
                        int h = heuristic(child, end);
                        int f = g + h;

                        // If the child is in the open list and the g value is higher, skip
                        if (openSet.find(child) != openSet.end() && g >= child->g)
                            continue;

                        child->parent = current;

                        child->g = g;
                        child->h = h;
                        child->f = f;

                        nodesToVisit.push(child);
                        openSet.insert(child);
                    }
                }
            }
        }

    }

    // No solution found
    return {};
}

void displayGrid(const vector<vector<Node>> &grid)
{
    vector<Node> obstacles;
    for (const auto &row : grid)
    {
        for (const auto &node : row)
        {
            if (node.obstacle)
            {
                cout << "0 ";
                obstacles.push_back(node);
            }
            else
            {
                cout << "1 ";
            }
        }
        cout << '\n';
    }
    cout << '\n';
    // for (auto &node : obstacles)
    // {
    //     cout << "Obstacle at: (" << node.x << ", " << node.y << ")\n";
    // }
    // cout << '\n';
}

int main()
{
    // 10x10 grid
    vector<vector<Node>> grid(10, vector<Node>(10, Node(0, 0)));

    // input
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            grid[i][j] = Node(i, j);
            if ((i == 5 && j > 2 && j < 7) || (j == 5 && i > 2 && i < 7))
            {
                grid[i][j].obstacle = true;
            }
        }
    }

    Node *start = &grid[0][0]; //(0,0)
    Node *end = &grid[9][9];   //(10,10)

    vector<Node *> path = aStar(grid, start, end);

    // Display
    displayGrid(grid);

    // Print the path
    if (!path.empty())
    {
        cout << "Path found:\n";
        for (Node *node : path)
        {
            cout << "(" << node->x << ", " << node->y << ")\n";
        }
    }
    else
    {
        cout << "No path found.\n";
    }

    return 0;
}