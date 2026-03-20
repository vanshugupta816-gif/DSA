#include <iostream>
using namespace std;

int getsingleElement(int arr[], int n){
    int Xor = 0;
    for(int i = 0; i < n; i++){
        Xor = Xor ^ arr[i];
    }
    return Xor;
}

int main(){
    int arr[] = {1, 1, 2, 3, 3, 4, 4};
    int n = 7;
    int result = getsingleElement(arr, n);
    cout << "Single element is: " << result << endl;
    return 0;
}
