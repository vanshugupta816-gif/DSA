#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> &arr, int day, int k, int m)
{
    int cnt = 0;
    int noOfB = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= day)
        {
            cnt++;
        }
        else
        {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}
int roseGarden(vector<int> &arr, int r, int b)
{
    long long val = 1LL * r * b;
    if (val > arr.size())
        return -1;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    int low = mini;
    int high = maxi;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(arr, mid, r, b))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> arr = {1, 2, 1, 2, 7, 2, 2, 3, 1};
    int R = 3; // Roses per bouquet
    int B = 2; // Number of bouquets
    int ans = roseGarden(arr, R, B);
    cout << "Minimum days required = " << ans << endl;
    return 0;
}
