#include <bits/stdc++.h>
using namespace std;
int findDays(vector<int> &weights, int cap)
{
    int days = 1;
    int load = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (weights[i] + load > cap)
        {
            days += 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return days;
}
int leastWeightCapacity(vector<int> &weights, int d)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int numberOfDays = findDays(weights, mid);
        if (numberOfDays <= d)
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
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int d = 5;
    int answer = leastWeightCapacity(weights, d);
    cout << "Minimum Capacity Required = " << answer << endl;
    return 0;
}
