#include <bits/stdc++.h>
using namespace std;
void firstAndLast_BR(int arr[], int n, int x)
{
    int first = -1, last = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            if (first == -1)
                first = i;
            last = i;
        }
    }
    cout << "First Occurrence Index = " << first << endl;
    cout << "Last Occurrence Index = " << last << endl;
}

// Lower Bound Function
int lowerBound(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
// Upper Bound Function
int upperBound(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
// Function to find First and Last Position
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int x)
{
    int lb = lowerBound(arr, n, x);
    if (lb == n || arr[lb] != x)
        return {-1, -1};
    return {lb, upperBound(arr, n, x) - 1};
}

// Function to find First Occurrence
int firstOccurrence(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == k)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return first;
}
// Function to find Last Occurrence
int lastOccurrence(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == k)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return last;
}
// Function to find First and Last Position
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = firstOccurrence(arr, n, k);
    if (first == -1)
        return {-1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}

int main()
{
    int arr[] = {2, 4, 5, 7, 5, 8, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    firstAndLast_BR(arr, n, x);

    // vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    // int n = arr.size();
    // int x = 8;
    // pair<int, int> ans = firstAndLastPosition(arr, n, x);
    // cout << "First Position = " << ans.first << endl;
    // cout << "Last Position = " << ans.second << endl;
    return 0;
}
