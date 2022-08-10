// //BINARYSEARCH USING ITERATION

// #include<iostream>
// using namespace std;

// void binarysearch(int arr[],int n,int target){
    
//     int s=0,e=n-1;

//     while(s <= e){
        
//         int mid = s+(e-s)/2;
        
//         if(arr[mid]==target){
//             cout<<"element found at index "<<mid;
//             return;
//         }
            
//         else if(arr[mid]>target)
//             e=mid-1;  
        
//         else
//             s=mid+1;
//     } 

//       cout<<"element not found";
// }


// int main(){
//     int n,target;
    
//     cout<<"enter size of array";
//     cin>>n;
    
//     int arr[n];
//     cout<<"enter sorted array";
    
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     cout<<"enter value whch you want to search";
//     cin>>target;
    
//     binarysearch(arr,n,target);
// }



// //BINARYSEARCH USING RECURSION

// #include<iostream>
// using namespace std;

// void binarysearch(int arr[],int s,int e,int target){
    
//     if(s > e){
//         cout<<"element not found";
//          return;
//     }
       
//         int mid = s+(e-s)/2;
        
//         if(arr[mid]==target){
//             cout<<"element found at index "<<mid;
//             return;
//         }
            
//         else if(arr[mid]>target)
//             binarysearch(arr,s,mid-1,target);
        
//         else
//             binarysearch(arr,mid+1,e,target);

      
// }

// int main(){
//     int n,target;
    
//     cout<<"enter size of array";
//     cin>>n;
    
//     int arr[n];
//     cout<<"enter sorted array";
    
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     cout<<"enter value whch you want to search";
//     cin>>target;
    
//     binarysearch(arr,0,n-1,target);
// }


//BINARY SEARCH IN 2-D MATRIX

#include<iostream>
#include<stdlib.h>
using namespace std;

void binarysearch2(int arr[4][4],int s,int e,int target){
    while(s <= e){
        
        int mid = e/2;
        
        if(arr[s][mid]==target){
            cout<<"element found at index "<<s<<" "<<mid;
            return;
        }
            
        else if(arr[s][mid]>target)
            e=mid-1;  
        
        else
            s=mid+1;
    } 

      cout<<"element not found";
      return;
}

void binarysearch(int arr[4][4],int n,int target){
    
    int low=0;
    int high=n-1;

    while(low<=high){
        if(arr[low][high]==target){
            cout<<"element found at index"<<low<<" "<<high;
            return;
        }
        else if(arr[low][0] <=target && arr[low][high] > target ){
            binarysearch2(arr,low,high,target);
            return;
        }
        else if(arr[low][high] < target)
        {
            low++;
        }
        else {
            high--;
        }
    }

}

int main(){
    int n=4,target;
    
    // cout<<"enter the size of array";
    // cin>>n;

    int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    // cout<<"enter array elements"<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cin>>arr[i][j];
    //     }
    // }

    cout<<"enter the target";
    
    cin>>target;
    binarysearch(arr,n,target);
    return 0;
}