#include <bits/stdc++.h>
using namespace std;
int findMax(vector<int> &v)
{
    int maxi = INT_MIN;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}
int calculateTotalHours(vector<int> &v, int hourly)
{
    int totalH = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        totalH += ceil((double)v[i] / (double)hourly);
    }
    return totalH;
}
int minimumRateToEatBananas(vector<int> v, int h)
{
    int low = 1;
    int high = findMax(v);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h)
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
    vector<int> v = {3, 6, 7, 11};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Minimum rate to eat bananas: " << ans << endl;
    return 0;
}
