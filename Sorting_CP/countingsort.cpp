//TC->O(n+k),n is the number of elements and k is the range
//SC->O(n+k)

//sorting according to keys
//counting the elements having distinct key values

//find the minimum and maximum value
//make max value as key
//create a count array of size k+1
//initialize count array as 0
//update count array
//store the values


#include<iostream>
using namespace std;

void countingsort(int arr[],int n){
    int max=0;
    int output[n];

    //find max value
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    } 

    //create count array
    int count[max+1]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    //Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }

    //first decrease the count[i], then store the value at indexes
    for(int i=n-1;i>=0;i--){
        output[--count[arr[i]]]=arr[i];
    }

    //update original array
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }

    //delete output array
   // delete []output;
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
    countingsort(arr,n);
    printarray(arr,n);
}

