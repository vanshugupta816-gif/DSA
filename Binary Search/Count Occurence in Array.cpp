#include <bits/stdc++.h>
using namespace std;

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
// Function to Count Occurrences
int countOccurrences(vector<int> &arr, int n, int x)
{
    pair<int, int> ans = firstAndLastPosition(arr, n, x);
    if (ans.first == -1)
        return 0;
    return ans.second - ans.first + 1;
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    int n = arr.size();
    int x = 8;
    int count = countOccurrences(arr, n, x);
    cout << "Total Occurrences = " << count << endl;
    return 0;
}
