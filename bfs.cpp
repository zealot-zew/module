#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int graph[10][10], nodeCount = 0;
vector<int> visited(10, -1);
void disconnected_BFS(int n);
void bfs(int startNode, int n);

int main()
{
    int n;
    cout << "Enter the number of vertices in the graph :";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
        }
    }
    disconnected_BFS(n);
    return 0;
}

void disconnected_BFS(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == -1)
        {
            bfs(i, n);
        }
    }
}

void bfs(int startNode, int n)
{
    queue<int> q;                     // Create an empty queue
    visited[startNode] = ++nodeCount; // Mark the start node as visited
    q.push(startNode);                // Add the start node to the queue

    cout << startNode; // Print the start node

    while (!q.empty()) // Repeat until the queue is empty
    {
        int current = q.front(); // Get the front node in the queue

        // Check all neighbors of 'current'
        for (int i = 1; i <= n; i++)
        {
            if (graph[current][i] == 1 && visited[i] == -1)
            {
                visited[i] = ++nodeCount; // Mark neighbor as visited
                cout << i;                // Print the node
                q.push(i);                // Add it to the queue
            }
        }

        q.pop(); // Remove the current node from the queue after checking all neighbors
    }
}
