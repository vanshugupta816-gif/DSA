#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            ans = min(ans, arr[mid]);
        }
    }
    return ans;
}

int findMin_OP(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // search space is already sorted
        if (arr[low] <= arr[high])
        {
            ans = min(ans, arr[low]);
            break;
        }
        // left part is sorted
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            ans = min(ans, arr[mid]);
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int minimum = findMin_OP(arr);
    cout << "Minimum element is: " << findMin(arr);
    return 0;
}
