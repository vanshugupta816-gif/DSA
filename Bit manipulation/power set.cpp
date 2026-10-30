#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> powerSet(vector<int> &arr)
{
    int n = arr.size();
    int total = 1 << n;
    vector<vector<int>> ans;
    for (int mask = 0; mask < total; mask++)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                subset.push_back(arr[i]);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans = powerSet(arr);
    for (auto subset : ans)
    {
        cout << "[";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i];
            if (i < subset.size() - 1)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}
