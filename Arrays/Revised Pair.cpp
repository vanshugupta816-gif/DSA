#include <bits/stdc++.h>
using namespace std;
int countReversePairs_BR(vector<int> &arr)
{
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > 2 * arr[j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}
int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
    {
        return cnt;
    }
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);      // Left Half
    cnt += mergeSort(arr, mid + 1, high); // Right Half
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}
int team(vector<int> &skill, int n)
{
    return mergeSort(skill, 0, n - 1);
}

int main()
{
    vector<int> arr = {1, 3, 2, 3, 1};
    int ans = countReversePairs_BR(arr);
    cout << "Reverse Pairs = " << ans;

    vector<int> skill = {4, 1, 2, 3, 1};
    int n = skill.size();
    int ans = team(skill, n);
    cout << "Reverse Pairs = " << ans;

    return 0;
}
