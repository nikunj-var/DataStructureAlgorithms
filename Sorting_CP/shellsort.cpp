//in shell sort we compare distant elements and swap them at their correct position.
//efficiency of shell sort is depicted by gap value
//first take the gap1 value as N/2 and in seond take gap1/2 and so on


#include<iostream>
using namespace std;

void shellsort(int arr[],int n){
    
    // Start with a big gap, then reduce the gap
    for(int gap=n/2;gap>0;gap/=2){
       int j=gap;

        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
       while(j<n){

             // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            for(int i=j-gap;i>=0;i=i-gap){
                if(arr[i+gap] > arr[i]){
                    break;
                }
                else{
                    swap(arr[i+gap],arr[i]);
                }
            }
            j++;
       }
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
    shellsort(arr,n);
    printarray(arr,n);
}