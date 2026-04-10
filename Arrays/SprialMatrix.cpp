#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            ans.push_back(mat[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            ans.push_back(mat[i][right]);
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5}
    };
    int n = mat.size();
    int m = mat[0].size();

    cout << "Original Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> ans = spiralMatrix(mat);
    cout << "\nSpiral Order:\n";
    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}
