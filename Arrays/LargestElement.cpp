#include<iostream>
using namespace std;
void LargestElement(int arr[], int n){
    int Largest = arr[0];
    for(int i = 0; i<n; i++){
        if(arr[i] > Largest)
        Largest = arr[i];
    }
    cout << "Largest element is: " << Largest;
}
int main(){
    int n = 5;
    int arr[] = {2, 3, 5, 2, 1};
     LargestElement(arr, n);
    return 0;
}
