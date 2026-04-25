#include<bits/stdc++.h>
using namespace std;
vector<int> majorityElement_BR(vector<int>& nums){
    int n = nums.size();
    vector<int> ls;
    int cnt;
    for(int i = 0; i < n-1; i++){
        if(ls.size() == 0 || ls[0] != nums[i]){
            cnt = 0;
            for(int j = 0; j < n-1; j++){
                if(nums[j] == nums[i])
                    cnt++;
            }
            if(cnt > n/3)
                ls.push_back(nums[i]);
        }
        if(ls.size() == 2)
            break;
    }
    return ls;
}

vector<int> majorityElement_BT(vector<int>& arr) {
    int n = arr.size();
    int mm = (n / 3) + 1;
    map<int, int> mpp;
    vector<int> ls;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
        if (mpp[arr[i]] == mm) {
            ls.push_back(arr[i]);
        }
    }
    return ls;
}

vector<int> majorityElement_OP(vector<int> v) {
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    for (int i = 0; i < v.size(); i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) {
            cnt1++;
        }
        else if (v[i] == el2) {
            cnt2++;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ls;
    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }
    int mini = (v.size() / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);
    sort(ls.begin(), ls.end());
    return ls;
}
int main(){
    vector<int> nums = {1,2,3,3,1,1,2,2};
    //vector<int> ans = majorityElement_BR(nums);
    //vector<int> ans = majorityElement_BT(nums);
    vector<int> ans = majorityElement_OP(nums);
    cout << "Majority Elements are: ";
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
