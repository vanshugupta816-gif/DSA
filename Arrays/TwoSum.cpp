#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> mpp;

    for(int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];

        if(mpp.find(need) != mpp.end()) {
            return {mpp[need], i};
        }

        mpp[nums[i]] = i;
    }

    return {-1, -1};
}

string read(int nums, vector<int> book, int target, int n)
{
    int left = 0, right = n - 1;

    sort(book.begin(), book.end());

    while (left < right) {
        int sum = book[left] + book[right];

        if (sum == target) {
            return "YES";
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    return "NO";
}

int main() {

    vector<int> nums = {2,7,11,15};
    int target = 9;

    //vector<int> ans = twoSum(nums, target);
    //cout << ans[0] << " " << ans[1];
    
    cout << read(nums.size(), nums, target, 5);

}
