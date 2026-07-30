#include <bits/stdc++.h>
using namespace std;
// Function to find the first occurrence of 1 in a sorted row
int lowerBound(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

// Function to find the row with the maximum number of 1s
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int cnt_max = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int firstOne = lowerBound(matrix[i], m, 1);
        int cnt_ones = m - firstOne;
        if (cnt_ones > cnt_max)
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

int main()
{
    vector<vector<int>> matrix = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = rowWithMax1s(matrix, n, m);
    cout << "Row with maximum number of 1s: " << ans << endl;
    return 0;
}
