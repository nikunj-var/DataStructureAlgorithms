//check if the array is pairwise sorted or not


#include<iostream>
using namespace std;

bool pairwisesorted(int arr[],int n){
    if(n==0 || n==1)
        return true;

    for(int i = 0;i < n-1;i += 2){
        if(arr[i] > arr[i+1] )
            return false;
    }

    return true;
}

int main(){
    int n;

    cout<<"enter size of array";
    cin>>n;
    
    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(pairwisesorted(arr,n))
        cout<<"sorted";
    else
        cout<<"not sorted";
    
}