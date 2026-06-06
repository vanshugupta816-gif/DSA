#include <bits/stdc++.h>
using namespace std;
int missingK(vector<int> vec, int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);

        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return k + high + 1;
}
int main()
{
    vector<int> vec = {2, 3, 4, 7, 11};
    int n = vec.size();
    int k = 5;
    cout << "Kth missing number = " << missingK(vec, n, k) << endl;
    return 0;
}
