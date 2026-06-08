#include <bits/stdc++.h>
using namespace std;

int allocation(vector<int> &a, int n, int pages)
{
    int students = 1;
    int std_page = 0;
    for (int i = 0; i < n; i++)
    {
        if (std_page + a[i] <= pages)
        {
            std_page += a[i];
        }
        else
        {
            students++;
            std_page = a[i];
        }
    }
    return students;
}
int max_el(vector<int> &a, int n)
{
    int maxi = a[0];
    for (int i = 1; i < n; i++)
    {
        maxi = max(maxi, a[i]);
    }
    return maxi;
}
int sum_of_arr(vector<int> &a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}
// Brute Force
int book_allocate_Br(vector<int> &a, int n, int students)
{
    if (students > n)
        return -1;
    int low = max_el(a, n);
    int high = sum_of_arr(a, n);
    for (int pages = low; pages <= high; pages++)
    {
        int cnt_std = allocation(a, n, pages);
        if (cnt_std == students)
        {
            return pages;
        }
    }
    return -1;
}
// Optimal (Binary Search)
int book_allocate_OP(vector<int> &a, int n, int students)
{
    if (students > n)
        return -1;
    int low = max_el(a, n);
    int high = sum_of_arr(a, n);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int requiredStudents = allocation(a, n, mid);
        if (requiredStudents <= students)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> books = {25, 46, 28, 49, 24};
    int students = 4;
    int n = books.size();
    cout << "Minimum pages: "
         << book_allocate_OP(books, n, students)
         << endl;
    return 0;
}
