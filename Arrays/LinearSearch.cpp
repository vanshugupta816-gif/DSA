#include<iostream>
using namespace std;

int linearsearch(int arr[], int n, int num){
    for(int i = 0; i < n; i++){
        if(arr[i] == num){
            return i;
        }
    }
    return -1;
}

int main(){

    int arr[] = {4, 5, 6, 2, 5};
    int n = 5;
    int num = 2;

    int result = linearsearch(arr, n, num);

    if(result != -1){
        cout << "Element found at index: " << result;
    }
    else{
        cout << "Element not found";
    }

    return 0;
}
