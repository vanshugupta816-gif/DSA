#include <bits/stdc++.h>
using namespace std;

int sumByD(vector<int> &arr, int div)
{
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sum = sum + ceil((double)arr[i]) / ((double)(div));
    }
    return sum;
}
int smallestdivisor(vector<int> &arr, int limit)
{
    int low = 0, high = *max_element(arr.begin(), arr.end());
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (sumByD(arr, mid) <= limit)
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
    vector<int> arr = {1, 2, 5, 9};
    int limit = 6;
    int ans = smallestdivisor(arr, limit);
    cout << "smallest divisor number:" << ans << endl;

    return 0;
}
