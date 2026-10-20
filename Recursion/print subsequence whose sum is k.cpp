#include <bits/stdc++.h>
using namespace std;
void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    // Pick
    ds.push_back(arr[ind]);
    s += arr[ind];
    printS(ind + 1, ds, s, sum, arr, n);
    s -= arr[ind];
    ds.pop_back();
    // Not pick
    printS(ind + 1, ds, s, sum, arr, n);
}

// print only one answer

bool print(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        // condition satisfied
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
            return true;
        }
        // condition not satisfied
        else
            return false;
    }
    // pick
    ds.push_back(arr[ind]);
    s += arr[ind];
    if (print(ind + 1, ds, s, sum, arr, n) == true)
    {
        return true;
    }
    s -= arr[ind];
    ds.pop_back();
    // not pick
    if (print(ind + 1, ds, s, sum, arr, n) == true)
        return true;
    return false;
}

// count the subsequence with sum k

int printC(int ind, int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        // condition satisfied
        if (s == sum)
            return 1;
        // condition not satisfied
        else
            return 0;
    }
    s += arr[ind];
    int l = printC(ind + 1, s, sum, arr, n);
    s -= arr[ind];
    // not pick
    int r = printC(ind + 1, s, sum, arr, n);
    return l + r;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    printS(0, ds, 0, sum, arr, n);
    return 0;
}
