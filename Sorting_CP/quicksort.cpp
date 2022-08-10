//MMM.IMP

//step1->first we have to take a element and put it into right side such that all the elements in the left side are lesser than the element and all the elements in the right side are greater than the element.
//step1 is called the partitioning


//in the function partition,following steps are follow->
//take a pivot element.
//count all elements less than pivot .
//put the pivot element at its correct place i.e. p->s+count
//all the left hand side elements of pivot are lesser than pivot and right side elements are greater than the pivot.
// after that take two pointers i and j points in beginning and end-
//if i is greater than pivot and j is less than pivot then swap them.
//else leave them as it is

#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){

    int pivot=arr[s];

    int count=0;
    //count numbers less than pivot
    for(int i=s;i<=e;i++){
        if(arr[i]<pivot)
            count++;
    }

    int pivotindex=s+count;
    swap(arr[s],arr[pivotindex]);

    int i=s;
    int j=e;

    while(i < pivotindex && j > pivotindex ){
        while(arr[i] < pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < pivotindex && j > pivotindex){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }

    return pivotindex;

}
void quicksort(int arr[],int s,int e){
    //base case
    if(s >= e)
        return;

    int p=partition(arr,s,e);

    //sort left side
    quicksort(arr,s,p-1);
    
    //sort right side
    quicksort(arr,p+1,e);    
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
    quicksort(arr,0,n-1);
    printarray(arr,n);
}

