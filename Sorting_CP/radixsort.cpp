#include<iostream>
using namespace std;

int getmax(int arr[],int n){
    int max;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

void countsort(int arr[],int n,int pos){
    int output[n];

    //create count array
    int count[10]={0};
    for(int i=0;i<n;i++){
        count[(arr[i]/pos)%10]++;
    }

    //Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for(int i=1;i<=9;i++){
        count[i]+=count[i-1];
    }

    //first decrease the count[i], then store the value at indexes
    for(int i=n-1;i>=0;i--){
        output[--count[(arr[i]/pos)%10]]=arr[i];
    }

    //update original array
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }

    //delete output array
   // delete []output;
}

void radixsort(int arr[],int n){
    int max=getmax(arr,n);
    for(int pos=1;max/pos>0;pos=pos*10){
        countsort(arr,n,pos);
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
    radixsort(arr,n);
    printarray(arr,n);
}

