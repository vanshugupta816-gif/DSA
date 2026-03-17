#include <iostream>
using namespace std;

void moveZero(int arr[], int n){
    int j = -1;

    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }

    if(j == -1)
        return;

    for(int i = j + 1; i < n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main(){

    int arr[] = {1, 3, 2, 0, 4, 0, 0, 5, 4, 1};
    int n = 10;

    moveZero(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
