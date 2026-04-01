#include <bits/stdc++.h>
using namespace std;

vector<int> superiorElements(vector<int>& a) {
    vector<int> ans;
    int maxi = INT_MIN;
    int n = a.size();
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > maxi) {
            ans.push_back(a[i]);
        }
        maxi = max(maxi, a[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main() {
     vector<int> arr = {2, 1, 5, 4, 3, 0, 0};

    vector<int> result = superiorElements(arr);

    cout << "Superior Elements: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
