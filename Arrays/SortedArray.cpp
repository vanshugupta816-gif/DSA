#include<iostream>
using namespace std;
bool isSorted(int arr[], int n){
    for(int i = 1; i<n; i++){
        if(arr[i] >= arr[i-1]){

        }else return false;
    }
    return true;
}
int main(){
    int n = 5;
    int arr [] = { 2, 1, 4, 5, 3};
    if(isSorted(arr, n))
        cout << "Array is sorted";
    else
        cout << "Array is not sorted";

    return 0;
}
