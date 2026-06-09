#include <bits/stdc++.h>
using namespace std;
int countStudents(vector<int> &arr, int pages)
{
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            pagesStudent += arr[i];
        }
        else
        {
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}
int findPages(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int students = countStudents(arr, mid);
        if (students > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    return findPages(boards, boards.size(), k);
}


int countPainters(vector<int> &boards, int maxLength)
{
    int painters = 1;
    long long currLength = 0;
    for (int i = 0; i < boards.size(); i++)
    {
        if (currLength + boards[i] <= maxLength)
        {
            currLength += boards[i];
        }
        else
        {
            painters++;
            currLength = boards[i];
        }
    }
    return painters;
}
int paintersPartition(vector<int> &boards, int k)
{
    int n = boards.size();
    if (k > n)
        return -1;
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int painters = countPainters(boards, mid);
        if (painters > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
int main()
{
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    cout << "Largest Minimum Distance: "
         << findLargestMinDistance(boards, k)
         << endl;

    cout << "Minimum time required = "
         << paintersPartition(boards, k)
         << endl;

    return 0;
}
