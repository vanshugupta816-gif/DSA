#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &a, int target)
{
    int low = 0, high = a.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (a[mid] == target)
            return mid;
        // Left side is sorted
        if (a[low] <= a[mid])
        {
            // Check if target lies in left half
            if (target >= a[low] && target <= a[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // Right half is sorted
        else
        {
            if (target >= a[mid] && target <= a[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> a = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int target = 3;
    int ans = search(a, target);
    cout << "Element found at index: " << ans;
    return 0;
}
