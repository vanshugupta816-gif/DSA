#include <bits/stdc++.h>
using namespace std;

bool solve(int i, int j, int index, vector<vector<char>> &board, string &word, vector<vector<bool>> &vis)
{
    // All letters of the word are found
    if (index == word.size())
    {
        return true;
    }
    int m = board.size();
    int n = board[0].size();
    // Check boundaries
    if (i < 0 || j < 0 || i >= m || j >= n)
    {
        return false;
    }
    // Check if cell is already visited
    if (vis[i][j])
    {
        return false;
    }
    // Check if the letter matches
    if (board[i][j] != word[index])
    {
        return false;
    }
    // Mark current cell as visited
    vis[i][j] = true;
    // Move down, up, right, or left
    bool found =
        solve(i + 1, j, index + 1, board, word, vis) ||
        solve(i - 1, j, index + 1, board, word, vis) ||
        solve(i, j + 1, index + 1, board, word, vis) ||
        solve(i, j - 1, index + 1, board, word, vis);
    // Backtrack: unmark the cell
    vis[i][j] = false;

    return found;
}

bool exist(vector<vector<char>> &board, string word)
{
    if (word.empty())
    {
        return true;
    }
    if (board.empty() || board[0].empty())
    {
        return false;
    }
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    // Try starting from every cell
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (solve(i, j, 0, board, word, vis))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCC";
    if (exist(board, word))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}
