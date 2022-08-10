//find the largest element in the array
//tc-O(n)
//sc-O(1)

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

void largestelement(int arr[],int n){
   int ans=0;
   for(int i = 0;i<n;i++){
        if(arr[i] > ans)
            ans=arr[i];
   }
   cout<<"largest element is "<<ans;
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

    largestelement(arr,n);
    
}

// FIND SMALLEST AND LARGEST ELEMENT IN THE ARRAY
// tc-O(n)
// sc-O(1)

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

void element(int arr[],int n){
   int ans1=0,ans2=INT_MAX;
   for(int i = 0;i<n;i++){
        if(arr[i] > ans1)
            ans1=arr[i];
        if(arr[i] < ans2)
            ans2=arr[i];    
   }
   cout<<"largest element is "<<ans1<<endl;
   cout<<"smallest element is "<<ans2;
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

    element(arr,n);
    
}

//approach2-minimise the comparison by comparing in pairs.
//works for even only
//tc-O(n)
//sc-O(1)


#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

void element(int arr[],int n){
   int ans1=0,ans2=INT_MAX;
   for(int i = 0;i<n-1;i+=2){
        if(arr[i] < arr[i+1]){
            if(arr[i] < ans2){
                ans2=arr[i];
            }
            if(arr[i+1] > ans1){
                ans1=arr[i+1];
            }
        }
        else{
            if(arr[i+1] < ans2){
                ans2=arr[i+1];
            }
            if(arr[i] > ans1){
                ans1=arr[i];
            }
        }
        
   }
   cout<<"largest element is "<<ans1<<endl;
   cout<<"smallest element is "<<ans2;
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

    element(arr,n);
    
}

//FIND THE SECOND LARGEST ELEMENT IN AN ARRAY
//APPROACH-FIND THE LARGEST ELEMENT WHICH NEEDS N-1 COMPARISON
//DELETE THE LARGEST ELEMENT
//again find the largest element needs n-2 comparison

//TOTAL NUMBER OF COMPARISON->N-1 + N-2=2N-3

