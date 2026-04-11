#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum_BT(vector<int> &arr, int k) {
    int n = arr.size();
    int count = 0;
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum += arr[j];
            if(sum == k) count++;
        }
    }
    return count;
}
int findAllSubarraysWithGivenSum_OP(vector<int> &arr, int k) {
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum]++;
    }
    return cnt; 
}
int main() {

    vector<int> arr = {1, 1, 2, 3, -2, 4, 1, 2};
    
    int k = 3;
    int result = findAllSubarraysWithGivenSum_OP(arr, k);
    int result = findAllSubarrayWithGivenSum_BT(arr, k);
    cout << "Number of subarrays with sum " << k << " = " << result << endl;
    return 0;
}
