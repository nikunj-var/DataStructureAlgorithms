// T.C-> O(nlogn)
// S.C-> O(1)

#include<iostream>
using namespace std;

void merge(int arr[],int s,int e){
    
    int mid=(s+e)/2;
    
    int len1=mid-s+1;
    
    int len2=e-mid;

    int *first=new int[len1];
    int *second=new int[len2];

    //copy values
    int k=s;
    
    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }
    
    k=mid+1;
    
    for(int i=0;i<len2;i++){
        second[i]=arr[k++];
    }

    //merge 2 sorted arrays

    int index1=0;
    int index2=0;
    k=s;
    while(index1<len1 && index2 < len2){
        if(first[index1]< second[index2]){
            arr[k++]=first[index1++];
        }
        else{
            arr[k++]=second[index2++];
        }
    }
    while(index1 < len1){
        arr[k++]=first[index1++];
    }
    
    while(index2 < len2){
        arr[k++]=second[index2++];
    }

    delete []first;
    delete []second;

}

void mergesort(int arr[],int s,int e){

    //base case
    if(s >= e)
        return;

    int mid=(s+e)/2;
    //left part sort karo pehle 
    mergesort(arr,s,mid);  

    //right part sort karo
    mergesort(arr,mid+1,e);     

    merge(arr,s,e);
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
    mergesort(arr,0,n-1);
    printarray(arr,n);
}



