#include <bits/stdc++.h>
using namespace std;
int func(vector<int> &greed, vector<int> &size)
{
    int n = greed.size();
    int m = size.size();
    int l = 0, r = 0;
    sort(greed.begin(), greed.end());
    sort(size.begin(), size.end());
    while (l < m && r < n)
    {
        if (greed[r] <= size[l])
        {
            r = r + 1;
        }
        l = l + 1;
    }
    return r;
}

int main()
{
    vector<int> greed = {1, 2, 3};
    vector<int> size = {1, 1};
    cout << func(greed, size) << endl;
    return 0;
}
