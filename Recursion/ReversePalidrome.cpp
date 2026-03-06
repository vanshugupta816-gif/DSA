#include<iostream>
using namespace std;
// bool palindrome(int i,int arr[], int n){
//     if(i>=n/2)
//     return true;
//     if(arr[i] != arr[n-i-1])
//     return false;
//     return palindrome(i+1,arr, n);
// }

 bool f (int i, string s){
    if(i >= s.size()/2)
    return true;
    if(s[i] != s[s.size()-i-1])
    return false;
    return f(i+1, s);
}
int main(){
    string s = "madam";
    cout << f(0,s);
    // int arr[] = {1, 2, 1};       
    // int n = 3;

    // cout << palindrome(0, arr, n);
    return 0;
}
