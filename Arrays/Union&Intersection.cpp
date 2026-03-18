#include<iostream>
#include<vector>
using namespace std;
// union
vector<int> sortedArray(vector<int> a, vector<int> b){
    int n1 = a.size();
    int n2 = b.size();

    int i = 0;
    int j = 0;
    vector<int> unionArr;

    while(i < n1 && j < n2){

        if(a[i] <= b[j]){
            if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while(j < n2){
        if(unionArr.size() == 0 || unionArr.back() != b[j]){
            unionArr.push_back(b[j]);
        }
        j++;
    }
    while(i < n1){
        if(unionArr.size() == 0 || unionArr.back() != a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
    }
    return unionArr;
}

// intersection
vector<int> findarrayIntersection(vector<int>& a, int n, vector<int>& b, int m){
    int j = 0;
    int i = 1;
    vector<int>ans;
    while (i<n && j<m){
    if (a[i] < b[j]){
        i++;
    }
    else if(b[j] < a[i]){      
        j++;
    }
    else{
        ans.push_back(a[i]);
        i++;
        j++;
    }
}
    return ans;
}

int main(){

    vector<int> arr1 = {1,2,2,3,4,5};
    vector<int> arr2 = {1,2,3,4,5,6};

    //vector<int> result = sortedArray(arr1, arr2);
    vector<int> result = findarrayIntersection(arr1, arr1.size(), arr2, arr2.size());

    for(int x : result){
        cout << x << " ";
    }
    return 0;
}

 
