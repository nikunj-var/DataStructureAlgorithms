<<<<<<< HEAD
//SOLUTION USING BINARYSEARCH
#include<iostream>
using namespace std;

int pivot(int arr[],int n){
    int s=0,e=n-1;
    int mid=s+(e-s)/2;
    
    while(s<e){
       if(arr[mid]>=arr[0]){
        s=mid+1;
       }
       else{
        e=mid;
       }
       mid=s+(e-s)/2;
    }
    return s;
}

int main(){
    int n,key;
    cin>>n;
    int arr[n];
    cout<<"enter array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter key";
    cin>>key;
    cout<<"pivot index"<<pivot(arr,n)<<endl;
   
=======
//SOLUTION USING BINARYSEARCH
#include<iostream>
using namespace std;

int pivot(int arr[],int n){
    int s=0,e=n-1;
    int mid=s+(e-s)/2;
    
    while(s<e){
       if(arr[mid]>=arr[0]){
        s=mid+1;
       }
       else{
        e=mid;
       }
       mid=s+(e-s)/2;
    }
    return s;
}

int main(){
    int n,key;
    cin>>n;
    int arr[n];
    cout<<"enter array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter key";
    cin>>key;
    cout<<"pivot index"<<pivot(arr,n)<<endl;
   
>>>>>>> 1cea996b1b95c9c182c43b40b1cb4d9b27c3bb86
}