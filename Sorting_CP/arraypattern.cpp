// GIVEN AN ARRAY CONVERT IT INTO AN ARRAY SUCH THAT A<B>C<D>E<F>...

//approach1-sort the array and reverse every adjacent elements
//tc-O(nlogn)
//sc-O(1)

#include<iostream>
#include<algorithm>
using namespace std;

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void convert(int arr[],int n){
    sort(arr,arr+n);
    printarray(arr,n);
    for(int i=0;i<n-1;i++){
        swap(arr[i],arr[i+1]);
    }
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
    convert(arr,n);
    printarray(arr,n);
}

//approach2-make sure all even positioned elemenets are greater than their adjacent odd elements,and do following steps
//i-if the current element is less than the previous one then swap them.(ii)same for next element
//tc-O(nlogn)
//sc-O(1)

#include<iostream>
#include<algorithm>
using namespace std;

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void convert(int arr[],int n){
    sort(arr,arr+n);
   for(int i=1;i<n;i+=2){
    if(i > 0 && arr[i-1] > arr[i]){
        swap(arr[i],arr[i-1]);
     }
    if(i < n-1 && arr[i] < arr[i+1]){
        swap(arr[i],arr[i+1]);
     }
   }
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
    convert(arr,n);
    printarray(arr,n);
}