//UNORDERED LINEAR SEARCH
//when array elements are not sorted then we have to apply unordered search in which we scan whole array


#include<iostream>
using namespace std;

bool unorderedLsearch(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target)
            return true;
    }
    return false;
}


int main(){
    int n,target;
    
    cout<<"enter size of array";
    cin>>n;
    
    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"enter value whch you want to search";
    cin>>target;
    
    if(unorderedLsearch(arr,n,target)){
        cout<<"element found";
    }
    else    
        cout<<"element not found";
}

// ORDERED LINEAR SEARCH
// when array elements is sorted then we have to apply ordered linear search.

#include<iostream>
using namespace std;

bool orderedLsearch(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target)
            return true;
        else if(arr[i] > target)
            return false;    
    }
    return false;
}


int main(){
    int n,target;
    
    cout<<"enter size of array";
    cin>>n;
    
    int arr[n];
    cout<<"enter sorted array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"enter value whch you want to search";
    cin>>target;
    
    if(orderedLsearch(arr,n,target)){
        cout<<"element found";
    }
    else    
        cout<<"element not found";
}



