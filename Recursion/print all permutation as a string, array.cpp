#include <bits/stdc++.h>
using namespace std;
// appraoch 1
void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, vector<int> &freq)
{
    // Base case
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    // Try every element
    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurPermute(ds, nums, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> freq(nums.size(), 0);
    recurPermute(ds, nums, ans, freq);
    return ans;
}

// approach 2

void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    recurPermute(0, nums, ans);
    return ans;
}

int main()
{
    // Input array
    vector<int> nums = {1, 2, 3};
    // Generate all permutations
    vector<vector<int>> ans = permute(nums);
    // Print the answer
    for (auto permutation : ans)
    {
        for (int value : permutation)
        {
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}
