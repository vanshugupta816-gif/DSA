#include<iostream>
#include<climits>
using namespace std;
void secondLargest(int arr[], int n){
    int Largest = arr[0];
    int secondLargest = -1;
    for(int i = 1; i<n; i++){
        if(arr[i] > Largest){
            secondLargest = Largest;
            Largest = arr[i];
        }
        else if (arr[i] < Largest && arr[i] > secondLargest){
            secondLargest = arr[i];
        }
    }
    cout << "second Largest element is: "<< secondLargest;
}
void secondSmallest(int arr[], int n){
    int Smallest = arr[0];
    int secondSmallest = INT_MAX;
    for(int i = 1; i<n; i++){
        if(arr[i] < Smallest){
            secondSmallest = Smallest;
            Smallest = arr[i];
        }
        else if (arr[i] != Smallest && arr[i] < secondSmallest){
            secondSmallest = arr[i];
        }
    }
    cout << "second Smallest element is: "<< secondSmallest;
}
int main(){
     int n = 6;
    int arr[] = {2, 3, 5, 2, 1, 4};
     secondLargest(arr, n);
     secondSmallest(arr, n);
    
    return 0;
}
