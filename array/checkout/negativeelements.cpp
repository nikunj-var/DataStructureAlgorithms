//move all the negative elements before positive elements

#include<iostream>
#include<algorithm>
using namespace std;


//approach1-
void movenegativeelements(int arr[],int n){
    int i=n-1;
    int j=n-1;
    while( i>=0 && j>=0 ){
        while(arr[i] > 0){
            i--;
        }
        while(arr[j] < 0){
            j--;
        }
        if(i >=0 && j >= 0){
            swap(arr[i],arr[j]);
        }
    }
}

//approach2-
void movenegativeelements(int arr[],int n){
    int i=0;
    int j=n-1;
    while( i < j ){
        if(arr[i] < 0 && arr[j] < 0){
            i++;
        }
        else if(arr[i] > 0 && arr[j] < 0){
            swap(arr[i++] , arr[j--]);
        }
        else if(arr[i] > 0 && arr[j] > 0){
            j--;
        }
        else{
            i++;
            j--;
        }
    }
}
void printarray(int arr[],int n){
    for(int i=0 ; i < n ; i++){
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

    movenegativeelements(arr,n);
    printarray(arr,n);
}