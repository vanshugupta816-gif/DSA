#include <bits/stdc++.h>
using namespace std;
int findMinIndex(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // search space is already sorted
        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            break;
        }
        // left half sorted
        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }
        // right half sorted
        else
        {
            if (arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }
    return index;
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int index = findMinIndex(arr);
    cout << "Index of minimum element: " << index << endl;
    return 0;
}
