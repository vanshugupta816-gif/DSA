#include<iostream>
using namespace std;
int removeDuplicate(int arr[], int n){
    int i = 0;
    for(int j = 1; j<n; j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}
int main(){
    int n = 7;
    int arr[] = {1, 1, 2, 3, 3, 4, 5};
    int newSize = removeDuplicate(arr, n);
    cout << "Array after removing duplicates:\n";
    for(int i = 0; i < newSize; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
