//approach1-binarysearch
//tc-O(logn)
//sc-O(1)

#include<iostream>
using namespace std;

int rotated(int arr[],int n){
    int first=0,last=n-1;
    int mid;
    while(first <= last){
        if(first == last)
            return arr[0];
        else if(first == last-1){
            return max(arr[0],arr[1]);
        }    
        else{
            mid=first + (last-first)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])
                return arr[mid];

            else if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1])    
                first = mid + 1;
            
            else 


            
                last = mid-1;
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

   cout<<"the element is"<<rotated(arr,n);
}



//IF THE ARRAY IS SORTED UNKNOWN NUMBER OF TIMES THEN, FIND PIVOT AND DIVIDE THE ARRAY INTO TWO SUBPARTS,
    //AFTER THAT CALL BINARY SEARCH

//approach2 -binarysearch
//tc-O(logn)
//sc-O(1)

#include<iostream>
using namespace std;



int findpivot(int arr[],int s,int e){
    
    if(e-s == 0)
        return s;
    else if(s == e-1){
        if(arr[s] >= arr[e]){
            return s;
        }
        else
            return e;
    }
       
    else{
        int mid=s+(e-s)/2;
        if(arr[s] >= arr[mid]){
            return findpivot(arr,s,mid);
        }
        else
            return findpivot(arr,mid,e);
    }        
}

int binarysearch(int arr[],int s,int e,int target){

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


int rotated(int arr[],int n,int target){
    
    int pivot=findpivot(arr,0,n-1);
    if(arr[pivot] == target){
        return pivot;
    }
    if(arr[pivot] <= target){
        return binarysearch(arr,0,pivot-1,target);
    }
    return binarysearch(arr, pivot+1 ,n-1,target);

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

   cout<<"the element index is"<<rotated(arr,n,target);
}


//approach3-solution in one scan instead of finding pivot
//tc-O(logn)
//sc-O(1)

#include<iostream>
using namespace std;

int rotated(int arr[],int s,int e,int target){
   int mid=s+(e-s)/2;

    if(s > e)
        return -1;

    if(target == arr[mid])
        return mid;

    //start half is in sorted order
    else if(arr[s] <= arr[mid]){
        if(target >= arr[s] && target < arr[mid]){
            return rotated(arr,s,mid-1,target);
        }
        else
            return rotated(arr,mid+1,e,target);
    }    
    //finish half is in sorted order
    else{
        if(target > arr[mid] && target <= arr[e])
            return rotated(arr,mid+1,e,target);
        else
            return rotated(arr,s,mid-1,target);
    }
}

int main(){
    int n,target;
    
    cout<<"enter size of array";
    cin>>n;
    
    cout<<"enter the value which you want to search";
    cin>> target;


    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

   cout<<"the element is"<<rotated(arr,0,n-1,target);
}

