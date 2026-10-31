#include <bits/stdc++.h>
using namespace std;

// approach 1
int singleNumber(vector<int> &nums)
{
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;
}
// approach 2

int findDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i += 3)
    {
        if (nums[i] != nums[i - 1])
        {
            return nums[i - 1];
        }
    }
    return nums[nums.size() - 1];
}

int main()
{
    vector<int> nums = {2, 2, 3, 2};
    cout << singleNumber(nums);
    return 0;
}
