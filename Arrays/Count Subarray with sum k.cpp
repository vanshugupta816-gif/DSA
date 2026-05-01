#include<bits/stdc++.h>
using namespace std;
int countSubarraysXOR_BR(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int xorr = 0;
            for (int k1 = i; k1 <= j; k1++) {
                xorr = xorr ^ arr[k1];
            }
            if (xorr == k) {
                count++;
            }
        }
    }
    return count;
}

int countSubarraysXOR_BT(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int xr = 0;
        for (int j = i; j < n; j++) {
            xr = xr ^ arr[j];

            if (xr == k) {
                count++;
            }
        }
    }
    return count;
}

int subarraysWithSumK_OP(vector<int> a, int k) {
    int xr = 0;
    map<int, int> mpp;
    mpp[xr] = 1;   // {0 : 1}
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        xr = xr ^ a[i];
        int x = xr ^ k;
        if (mpp.find(x) != mpp.end()) {
            cnt += mpp[x];
        }
        mpp[xr]++;
    }
    return cnt;
}

int main(){
    //  int arr[] = {4, 2, 2, 6, 4};  
    //  vector<int> arr = {4, 2, 2, 6, 4};
    // int n = 5;
    // int k = 6; 
    // int result = countSubarraysXOR_BR(arr, n, k);
    // int result = countSubarraysXOR_BT(arr, n, k);
    // int result = subarraysWithSumK_OP(arr, k);
    // cout << "Number of subarrays with XOR = " << k << " is: " << result;
    //  cout << "Number of subarrays with XOR = " << k << " is: " << result;
    return 0;
}
