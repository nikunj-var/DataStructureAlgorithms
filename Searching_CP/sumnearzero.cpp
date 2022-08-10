//question->two elements whose sum is near to zero

// //approach1-for each element find the sum with every other element and return the min sum near to zero
// //tc-O(n^2)
// //sc-O(1)

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

void sumnearzero(int arr[],int n,int target){
    int mini=INT_MAX;
    int newi,newj;
    for(int i=0;i<n-1;i++){
        int sum=0;
        for(int j=i+1;j<n;j++){
            sum=arr[i]+arr[j];
            if(abs(sum) < abs(mini)){
                newi=i;
                newj=j;
                mini=sum;
            }
        }
    }
    cout<<"sum nearest to zero"<<arr[newi]<<" "<<arr[newj]<<" "<<mini;
}


int main(){
    int n;
    int target;
    cout<<"enter size of array";
    cin>>n;
    
    cout<<"enter target value";
    cin>>target;

    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    sumnearzero(arr,n,target);
}

//approach2-use sorting and apply two pointer approach-if the current pair is greater than zero and less than positive closest update the positive closest and decrement j.
        //ii-if current pair is less than zero and greater than 
//tc-O(nlogn)
//sc-O(1)

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

void sumnearzero(int arr[],int n){
    int smallp=INT_MAX,smalln=INT_MIN;
    int i=0,j=n-1;
    while( i < j){
        int sum=arr[i]+arr[j];
       if(sum > 0){
            if(sum < smallp){
                smallp=sum;
            }
            j--;
       }
       else if(sum < 0){
            if(sum > smalln){
                smalln=sum;
            }
            i++;
       }
    }
    cout<<arr[i]<<" "<<arr[j];
    
}


int main(){
    int n;
    int target;
    cout<<"enter size of array";
    cin>>n;

    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    sumnearzero(arr,n);
}

