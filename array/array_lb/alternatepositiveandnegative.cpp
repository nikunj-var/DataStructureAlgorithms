#include<bits/stdc++.h>
using namespace std;

void rightrotate(int arr[],int outofplace,int index){
    int temp=arr[index];

    for(int i=index;i>outofplace;i--){
        arr[i]=arr[i-1];
    }
    arr[outofplace]=temp;
}


void rearrange(int arr[],int n){
    int outofplace=-1;

    for(int index=0 ; index<n ; index++){

        if(outofplace >= 0){
            if((arr[index] >= 0 && arr[outofplace] < 0 ) || (arr[index] < 0 && arr[outofplace] >= 0))
            {
                rightrotate(arr,outofplace,index);
                if(index-outofplace >= 2){
                    outofplace+=2;
                }
                else{
                    outofplace=-1;
                }
            }
        }

        if(outofplace == -1){
            if((arr[index] < 0 && index%2 != 0) || (arr[index] >= 0 && index%2 == 0)){
                outofplace=index;
            }
            else
                outofplace=-1;
        }
    }
}

int main(){
    int n;
    cout<<"enter array size";
    cin>>n;
    int arr=new int[n];
    cout<<"enter array elements";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rearrange(arr,n);
    
    for(int i=0;i<n;i++){
        cout<<"\narray elements are"<<arr[i]<<" ";
    }
}