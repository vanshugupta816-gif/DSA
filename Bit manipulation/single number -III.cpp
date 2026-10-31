#include <bits/stdc++.h>
using namespace std;
vector<int> singleNumber(vector<int> &nums)
{
    int xorr = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        xorr = xorr ^ nums[i];
    }
    int rightmost = (xorr & (xorr - 1)) & xorr;
    int b1 = 0;
    int b2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] & rightmost)
        {
            b1 = b1 ^ nums[i];
        }
        else
        {
            b2 = b2 ^ nums[i];
        }
    }
    return {b1, b2};
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> ans = singleNumber(nums);
    cout << "The two numbers are: "
         << ans[0] << " " << ans[1] << endl;
    return 0;
}
