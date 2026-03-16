#include<iostream>
using namespace std;
void leftRotate(int arr[], int n, int d){
     d = d % n;
    int temp[d];
    for(int i = 0; i<d; i++){
        temp[i] = arr[i];
    }
    for(int i = d; i<n; i++){
        arr[i-d] = arr[i];
    }
    for(int i = n-d; i<n; i++){
        arr[i] = temp[i-(n-d)];
    }
}
int main(){
    int arr[] {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int d = 3;
    leftRotate(arr, n, d);
    cout << "Rotate array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
     return 0;
}
