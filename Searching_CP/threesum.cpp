
//approach1-brute force
//tc-O(n^3)
//sc-O(1)
#include<iostream>
using namespace std;

void threesum(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;j<n;j++){
                if(arr[i]+arr[j]+arr[k]==target){
                    cout<<"the three values are"<<" "<<arr[i]<<" "<<arr[j]<<" "<<arr[k];
                    return;
                }

            } 
        }
    }
    cout<<"not found";
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

    cout<<"enter target value";
    cin>>target;

    threesum(arr,n,target);
}

//approach2-sort the array and apply a for loop with two pointer approach
//tc-O(n^2)
//sc-O(1)

#include<iostream>
#include<algorithm>
using namespace std;

void threesum(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        int j=i+1,k=n-1;
      
        while(j < k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum==target){
                cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k];
                return;
            }
            else if(sum < target){
                j++;
            }
            else{
                k--;
            }
        }
    }
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

    cout<<"enter target value";
    cin>>target;

    sort(arr,arr+n);

    threesum(arr,n,target);
}



//approach2-use hashing
//tc-O(n^2)
//sc-O(n)


//THREE SUM NEAREST TO ZERO


// #include<iostream>
// #include<algorithm>
// #include<climits>
// using namespace std;

// class sum{
//     public:
//         int i;
//         int j;
//         int k;
//         int minsum;
// };
// void threesumnearzero(int arr[],int n,int target){
//     int smallp=INT_MAX;
//     int smalln=INT_MIN;
//     int mini;
//     int newi,newj,newk;
//     for(int i=0;i<n;i++){
//         int j=i+1,k=n-1;
      
//         while(j < k){
//             int sum=arr[i]+arr[j]+arr[k];
//             if(sum > 0){
//                 if(sum < smallp){
//                     smallp=sum;
//                 }
//                 k--;
//             }
//             else if(sum < 0){
//                 if(sum > smalln){
//                     smalln=sum;
//                 }
//                 j++;
//             }
//             else{
//                 cout<<arr[i]<<" "<< arr[j]<<" "<<  arr[k]<<" "<<endl;
//             }
//         }
//     }
// }

// int main(){
//     int n,target;
    
//     cout<<"enter size of array";
//     cin>>n;
    
//     int arr[n];
//     cout<<"enter array";
    
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     cout<<"enter target value";
//     cin>>target;

//     sort(arr,arr+n);

//     threesumnearzero(arr,n,target);
// }