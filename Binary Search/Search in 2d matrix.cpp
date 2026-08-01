#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (!matrix.size())
        return false;
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = (n * m) - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (matrix[mid / m][mid % m] == target)
        {
            return true;
        }
        if (matrix[mid / m][mid % m] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

// search matrix in 2d - II

bool searchElement(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int row = 0, col = m - 1;
    while ((row < n && col >= 0))
    {
        if (mat[row][col] == target)
            return true;
        else if (mat[row][col] < target)
            row++;
        else
            col--;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};
    int target = 3; // Change the target here
    if (searchElement(matrix, target))
        cout << "Element Found" << endl;
    else
        cout << "Element Not Found" << endl;
    return 0;
}
