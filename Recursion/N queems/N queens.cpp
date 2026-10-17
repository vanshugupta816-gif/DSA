#include <bits/stdc++.h>
using namespace std;

bool isSafe1(int row, int col, vector<string> board, int n)
{
    // Check upper diagonal
    int duprow = row;
    int dupcol = col;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;

        row--;
        col--;
    }
    // Check left side
    col = dupcol;
    row = duprow;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    // Check lower diagonal
    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    // If all columns are filled
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    // Try placing queen in every row
    for (int row = 0; row < n; row++)
    {
        if (isSafe1(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            // Backtracking
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(0, board, ans, n);
    return ans;
}

// 2nd approach

void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
{
    // All columns are filled
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    // Try every row in the current column
    for (int row = 0; row < n; row++)
    {
        // Check if placing queen is safe
        if (leftRow[row] == 0 &&
            lowerDiagonal[row + col] == 0 &&
            upperDiagonal[n - 1 + col - row] == 0)
        {

            // Place queen
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;

            // Move to next column
            solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
            // Backtracking
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    vector<int> leftRow(n, 0);
    vector<int> upperDiagonal(2 * n - 1, 0);
    vector<int> lowerDiagonal(2 * n - 1, 0);
    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
    return ans;
}

int main()
{
    // We are directly giving n = 4
    int n = 4;
    vector<vector<string>> result = solveNQueens(n);
    // Print all solutions
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Solution " << i + 1 << ":\n";
        for (string row : result[i])
        {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
