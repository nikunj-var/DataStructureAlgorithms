
//FIRST OCCURENCE OF A NUMBER IN A ARRAY

//approach1-binary searcg
//tc-O(logn)
//sc-O(1)

#include<iostream>
#include<algorithm>
using namespace std;

int firstoccurence(int arr[],int n,int data){
    int s=0,e=n-1;
    
    while(s <= e){
        int mid=s + (e-s)/2;

        if((mid == s && arr[mid]==data) || (arr[mid] == data && arr[mid-1] < data))
            return mid;

        else if(arr[mid] >= data){
            e=mid-1;
        }    
        else
            s=mid+1;
    }

    return -1;
}

int main(){
    int n;
    int target;

    cout<<"enter size of array";
    cin>>n;
    
    cout<<"enter the value which you want to search";
    cin>> target;

    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

   cout<<"the first occurence of element index is"<<firstoccurence(arr,n,target);
}

// LAST OCCURENCE OF A NUMBER IN A ARRAY

// approach1-binary searcg
// tc-O(logn)
// sc-O(1)

#include<iostream>
#include<algorithm>
using namespace std;

int lastoccurence(int arr[],int n,int data){
    int s=0,e=n-1;
    
    while(s <= e){
        int mid=s + (e-s)/2;

        if((mid == e && arr[mid]==data) || (arr[mid] == data && arr[mid+1] > data))
            return mid;

        else if(arr[mid] <= data){
            s=mid+1;
        }    
        else
            e=mid-1;
    }

    return -1;
}

int main(){
    int n;
    int target;

    cout<<"enter size of array";
    cin>>n;
    
    cout<<"enter the value which you want to search";
    cin>> target;

    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

   cout<<"the last occurence of element index is"<<lastoccurence(arr,n,target);
}


//COUNT THE NUMBER OF OCCURENCES OF AN ELEMENT IN A ARRAY

//approach1- linear search
//tc-O(n)
//sc-O(1)

#include<iostream>
#include<algorithm>
using namespace std;

int countoccurence(int arr[],int n,int data){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==data)
            count++;
    }
    return count;
}

int main(){
    int n;
    int target;

    cout<<"enter size of array";
    cin>>n;
    
    cout<<"enter the value which you want to search";
    cin>> target;

    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

   cout<<"the number of occurences of an element is"<<countoccurence(arr,n,target);
}

//approach2- using one binary search scan with other small scan
//tc-O(n+S) where s is the occurence of number
//sc-O(1)

#include<iostream>
#include<algorithm>
using namespace std;

int binarysearch(int arr[],int n,int target){    
    int s=0,e=n-1;

    while(s <= e){
        
        int mid = s+(e-s)/2;
        
        if(arr[mid]==target){
            return mid;
        }
            
        else if(arr[mid]>target)
            e=mid-1;  
        
        else
            s=mid+1;
    } 

    return -1;
}


int countoccurence(int arr[],int n,int data,int pos){
    
    int lcount=0,rcount=0;

    for(int i=pos;i>=0;i--){
        if(arr[i]==data){
            lcount++;
        }
        else{
            break;
        }
    }
    for(int i=pos;i<n;i++){
        if(arr[i]==data){
            rcount++;
        }
        else{
            break;
        }
    }

    return lcount+rcount-1;

}

int main(){
    int n;
    int target;

    cout<<"enter size of array";
    cin>>n;
    
    cout<<"enter the value which you want to search";
    cin>> target;

    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int pos=binarysearch(arr,n,target);

   cout<<"the number of occurences of an element is"<<countoccurence(arr,n,target,pos);
}

//approach3-first call firstoccurence fun then right occurence and return rcount-lcount+1
//tc-O(logn)
//sc-O(1)


#include<iostream>
#include<algorithm>
using namespace std;

int firstoccurence(int arr[],int n,int data){
    int s=0,e=n-1;
    
    while(s <= e){
        int mid=s + (e-s)/2;

        if((mid == s && arr[mid]==data) || (arr[mid] == data && arr[mid-1] < data))
            return mid;

        else if(arr[mid] >= data){
            e=mid-1;
        }    
        else
            s=mid+1;
    }

    return -1;
}

int lastoccurence(int arr[],int n,int data){
    int s=0,e=n-1;
    
    while(s <= e){
        int mid=s + (e-s)/2;

        if((mid == e && arr[mid]==data) || (arr[mid] == data && arr[mid+1] > data))
            return mid;

        else if(arr[mid] <= data){
            s=mid+1;
        }    
        else
            e=mid-1;
    }

    return -1;
}

int main(){
    int n;
    int target;

    cout<<"enter size of array";
    cin>>n;
    
    cout<<"enter the value which you want to search";
    cin>> target;

    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int lcount=firstoccurence(arr,n,target);
    int rcount=lastoccurence(arr,n,target);

   cout<<"the number of occurences of an element is"<<rcount-lcount+1;
}