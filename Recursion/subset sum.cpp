#include <bits/stdc++.h>
using namespace std;
void func(int ind, int sum, vector<int> &arr, int N, vector<int> &sumSubset)
{
    if (ind == N)
    {
        sumSubset.push_back(sum);
        return;
    }
    // Pick the element
    func(ind + 1, sum + arr[ind], arr, N, sumSubset);
    // Do not pick the element
    func(ind + 1, sum, arr, N, sumSubset);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> sumSubset;
    func(0, 0, arr, N, sumSubset);
    sort(sumSubset.begin(), sumSubset.end());
    return sumSubset;
}

// subset sum 2

void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    // Store the current subset
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        // Skip duplicate elements
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        // Pick the element
        ds.push_back(nums[i]);
        // Recursive call
        findSubsets(i + 1, nums, ds, ans);
        // Backtrack
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    // Sort so duplicate elements come together
    sort(nums.begin(), nums.end());
    findSubsets(0, nums, ds, ans);
    return ans;
}

int main()
{
    // No cin - directly giving the array
    vector<int> arr = {3, 1, 2};
    int N = arr.size();
    vector<int> result = subsetSums(arr, N);
    // Print all subset sums
    for (int sum : result)
    {
        cout << sum << " ";
    }
    return 0;
}
