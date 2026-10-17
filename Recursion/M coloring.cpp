#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && graph[k][node] == 1 && color[k] == col)
        {
            return false;
        }
    }
    return true;
}

bool solve(int node, int color[], int m, int N, bool graph[101][101])
{
    if (node == N)
    {
        return true;
    }
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, graph, N, i))
        {
            color[node] = i;
            if (solve(node + 1, color, m, N, graph))
            {
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}
// Function to determine whether the graph can be
// coloured with at most M colours such that no two
// adjacent vertices have the same colour.
bool graphColoring(bool graph[101][101], int m, int N)
{
    int color[N] = {0};
    if (solve(0, color, m, N, graph))
    {
        return true;
    }
    return false;
}

int main()
{
    int N = 4;
    int M = 3;
    bool graph[101][101] = {false};
    // Edges: 0-1, 0-2, 1-2, 1-3, 2-3
    graph[0][1] = graph[1][0] = true;
    graph[0][2] = graph[2][0] = true;
    graph[1][2] = graph[2][1] = true;
    graph[1][3] = graph[3][1] = true;
    graph[2][3] = graph[3][2] = true;
    if (graphColoring(graph, M, N))
    {
        cout << "The graph can be coloured using at most "
             << M << " colours." << endl;
    }
    else
    {
        cout << "The graph cannot be coloured using "
             << M << " colours." << endl;
    }
    return 0;
}
