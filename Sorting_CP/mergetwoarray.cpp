//merge two arrays ,first array has m elements and have m+n size and other array has n elements with n size of the array

//approach-
// Let first array be mPlusN[] and other array be N[]
// 1) Move m elements of mPlusN[] to end.
// 2) Start from nth element of mPlusN[] and 0th 
//    element of N[] and merge them into mPlusN[].

#include<iostream>
#include<algorithm>
using namespace std;

void printarray(int arr[],int n){
    cout<<"array size is "<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void merge(int arr1[],int arr2[],int m,int n){
    int j=m-1;     
    for(int i=m-1;i>=0;i--){
       if(arr1[i]!=-1){
            arr1[j]=arr1[i];
            j--;
       }
    }
    int i=n;
    j=0;
    
    for(int k=0;k<m;k++){
        if((j==n)||(i < m && arr1[i] <= arr2[j])){
            arr1[k]=arr1[i];
            i++;
        }
        else{
            arr1[k]=arr2[j];
            j++;
        }
    } 
}
int main(){
    int m,n;
    cout<<"enter the value of m";
    cin>>m;
    cout<<"enter the value of n";
    cin>>n;
    int arr1[m];
    int arr2[n];
    cout<<"enter array1";
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }
    cout<<"enter array 2";
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    merge(arr1,arr2,m,n);
    printarray(arr1,m);
}+