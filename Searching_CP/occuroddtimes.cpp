//FIND THE NUMBER OCCURING AN ODD NUMBER OF TIMES -
#include<iostream>
using namespace std;

int oddtimes(int arr[],int n){
    int ans=arr[0];
    for(int i=1;i<n;i++){
        ans^=arr[i];
    }
    return ans;
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

   cout<<"odd number of times the number is"<<oddtimes(arr,n);
}