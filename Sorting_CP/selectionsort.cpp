//The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning

// time complexity = O(N)*O(N) = O(N*N) = O(N2)

// Auxiliary Space: O(1) 

#include<iostream>
using namespace std;

void selectionsort(int arr[],int n){
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j])
                min=j;
        }
        swap(arr[min],arr[i]);
    }

}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
    selectionsort(arr,n);
    printarray(arr,n);
}

