#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int bs_RC(vector<int> &nums, int low, int high, int target)
{

    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (nums[mid] == target)
        return mid;

    else if (target > nums[mid])
        return bs_RC(nums, mid + 1, high, target);

    return bs_RC(nums, low, high - 1, target);
}

int search(vector<int> &nums, int target)
{

    return bs_RC(nums, 0, nums.size() - 1, target);
}

int main()
{
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int target = 7;
    int result = search(nums, target);
    cout << "Index of target is: " << result;

    // vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    // int target = 5;
    // int ans = search(nums, target);
    // if (ans != -1)
    //     cout << "Element found at index: " << ans;
    // else
    //     cout << "Element not found";

    return 0;
}
