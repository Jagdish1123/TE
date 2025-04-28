#include <bits/stdc++.h>
using namespace std;

// Directions
const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Goal state
const vector<int> goalState = {1, 2, 3, 4, 5, 6, 7, 8, 0};

// Function to display the grid
void printGrid(const vector<int> &state)
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && i != 0)
            cout << endl;
        cout << state[i] << " ";
    }
    cout << endl;
}

// Calculate the heuristic
int heuristic(const vector<int> &state)
{
    int distance = 0;
    for (int i = 0; i < 9; ++i)
    {
        if (state[i] == 0)
            continue;
        int goalPos = state[i] - 1;
        int x1 = i / 3, y1 = i % 3;
        int x2 = goalPos / 3, y2 = goalPos % 3;
        distance += abs(x1 - x2) + abs(y1 - y2);
    }
    return distance;
}

// Checking if the state is the goal state
bool isGoalState(const vector<int> &state)
{
    return state == goalState;
}

// Check if the puzzle is solvable
bool isSolvable(const vector<int> &state)
{
    int inversions = 0;
    for (size_t i = 0; i < state.size(); ++i)
    {
        for (size_t j = i + 1; j < state.size(); ++j)
        {
            if (state[i] != 0 && state[j] != 0 && state[i] > state[j])
            {
                ++inversions;
            }
        }
    }
    return inversions % 2 == 0;
}

// A* Search algorithm
vector<vector<int>> solvePuzzle(vector<int> startState)
{
    // Input validation
    if (startState.size() != 9)
    {
        cerr << "Error: Invalid puzzle size. The puzzle should have exactly 9 tiles (3x3)." << endl;
        return {};
    }

    // Check if the puzzle is solvable
    if (!isSolvable(startState))
    {
        cerr << "Error: The initial puzzle configuration is unsolvable." << endl;
        return {};
    }

    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
    unordered_map<string, int> visited;
    pq.push({heuristic(startState), startState});
    visited[string(startState.begin(), startState.end())] = 0;

    unordered_map<string, vector<int>> parent;
    unordered_map<string, pair<int, int>> moveFrom;

    while (!pq.empty())
    {
        auto [currentCost, currentState] = pq.top();
        pq.pop();

        if (isGoalState(currentState))
        {
            vector<vector<int>> path;
            while (parent.count(string(currentState.begin(), currentState.end())))
            {
                path.push_back(currentState);
                currentState = parent[string(currentState.begin(), currentState.end())];
            }
            path.push_back(currentState);
            reverse(path.begin(), path.end());
            return path;
        }

        int blankIndex = find(currentState.begin(), currentState.end(), 0) - currentState.begin();
        int blankRow = blankIndex / 3, blankCol = blankIndex % 3;

        // Iterate over possible directions to move the blank space
        for (auto &[dx, dy] : directions)
        {
            // Print the direction based on dx, dy
            if (dx == -1 && dy == 0)
            {
                cout << "Direction: Up" << endl;
            }
            else if (dx == 1 && dy == 0)
            {
                cout << "Direction: Down" << endl;
            }
            else if (dx == 0 && dy == -1)
            {
                cout << "Direction: Left" << endl;
            }
            else if (dx == 0 && dy == 1)
            {
                cout << "Direction: Right" << endl;
            }

            int newRow = blankRow + dx, newCol = blankCol + dy;
            if (newRow < 0 || newRow >= 3 || newCol < 0 || newCol >= 3)
                continue;

            int newBlankIndex = newRow * 3 + newCol;
            vector<int> nextState = currentState;
            swap(nextState[blankIndex], nextState[newBlankIndex]);

            string nextStateStr(nextState.begin(), nextState.end());

            // If this state has not been visited yet
            if (!visited.count(nextStateStr))
            {
                visited[nextStateStr] = visited[string(currentState.begin(), currentState.end())] + 1;
                pq.push({visited[nextStateStr] + heuristic(nextState), nextState});
                parent[nextStateStr] = currentState;
                moveFrom[nextStateStr] = {dx, dy};
            }

            // Print the grid before and after swapping and the heuristic value
            cout << "Before swap:" << endl;
            printGrid(currentState);
            cout << "After swap:" << endl;
            printGrid(nextState);

            int nextHeuristic = heuristic(nextState);
            cout << "Heuristic value for this state: " << nextHeuristic << endl;
            cout << "---------------------------" << endl;
        }

        // After processing all directions for the current blank space, print the message
        cout << "\n------------>All children are over for this position<------------\n"
             << endl;
    }

    return {};
}

int main()
{
    vector<int> startState = {1, 2, 3, 4, 6, 0, 7, 5, 8};
    cout << "Input:" << endl;
    printGrid(startState);

    vector<vector<int>> solution = solvePuzzle(startState);

    cout << "Solution Path--->>>:" << endl;
    for (const auto &state : solution)
    {
        printGrid(state);
        cout << "---------" << endl;
    }

    return 0;
}
