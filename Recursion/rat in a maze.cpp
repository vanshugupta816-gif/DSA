#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis)
{
    // Base case: destination reached
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }

    // Downward
    if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1)
    {
        vis[i][j] = 1;
        solve(i + 1, j, a, n, ans, move + 'D', vis);
        vis[i][j] = 0;
    }

    // Left
    if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1)
    {
        vis[i][j] = 1;
        solve(i, j - 1, a, n, ans, move + 'L', vis);
        vis[i][j] = 0;
    }

    // Right
    if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1)
    {
        vis[i][j] = 1;
        solve(i, j + 1, a, n, ans, move + 'R', vis);
        vis[i][j] = 0;
    }

    // Upward
    if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1)
    {
        vis[i][j] = 1;
        solve(i - 1, j, a, n, ans, move + 'U', vis);
        vis[i][j] = 0;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    // Start only if the first cell is open
    if (n > 0 && m[0][0] == 1)
    {
        solve(0, 0, m, n, ans, "", vis);
    }
    return ans;
}

// short code

void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis, int di[], int dj[])
{
    // Base case
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++)
    {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        // Check boundaries, visited cells, and open cells
        if (nexti >= 0 && nextj >= 0 &&
            nexti < n && nextj < n &&
            !vis[nexti][nextj] && a[nexti][nextj] == 1)
        {
            vis[i][j] = 1;
            solve(nexti, nextj, a, n, ans,
                  move + dir[ind], vis, di, dj);
            vis[i][j] = 0;
        }
    }
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    // Direction order: Down, Left, Right, Up
    int di[] = {1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    if (n > 0 && m[0][0] == 1)
    {
        solve(0, 0, m, n, ans, "", vis, di, dj);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the maze: ";
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter the maze (0 = blocked, 1 = open):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    vector<string> paths = findPath(maze, n);
    if (paths.empty())
    {
        cout << "No path exists.\n";
    }
    else
    {
        cout << "All possible paths are:\n";
        for (const string &path : paths)
        {
            cout << path << '\n';
        }
    }
    return 0;
}
