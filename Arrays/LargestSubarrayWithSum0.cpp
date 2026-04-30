#include<bits/stdc++.h>
using namespace std;
int maxLen(int A[], int n) {
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        if (sum == 0) {
            maxi = i + 1;
        } 
        else {
            if (mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]);
            } 
            else {
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}
int main(){
    int A[] = {1, -1, 3, 2, -2, -3, 3};
    int n = sizeof(A) / sizeof(A[0]);
    int result = maxLen(A, n);
    cout << "Maximum length of subarray with sum 0: " << result << endl;
    return 0;
}
