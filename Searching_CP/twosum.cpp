// // //approach1-brute force
// // //tc-O(n^2)
// // //sc-O(1)

#include<iostream>
using namespace std;

void twosum(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i]+arr[j]==target){
                cout<<arr[i]<<" "<<arr[j]<<endl;
                return;
            }
        }
    }
    cout<<"no solution";
}

int main(){
    int n;
    int target;
    cout<<"enter size of array";
    cin>>n;
    
    cout<<"enter target value";
    cin>>target;

    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    twosum(arr,n,target);
}

// //approach2-sort the array and apply two pointer approach
// //tc-O(nlogn)
// //sc-O(1)

#include<iostream>
#include<algorithm>
using namespace std;

void twosum(int arr[],int n,int target){
    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i]+arr[j]==target){
            cout<<arr[i]<<" "<<arr[j]<<endl;
            return;
        }
        else if((arr[i]+arr[j])>target){
            j--;   
        }
        else{
            i++;
        }
    }
    cout<<"no solution exists";
}


int main(){
    int n;
    int target;
    cout<<"enter size of array";
    cin>>n;
    
    cout<<"enter target value";
    cin>>target;

    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    twosum(arr,n,target);
}

//approach3-use hashtable
//tc-O(n)
//sc-O(n)



//QUESTION - GIVEN AN ARRAY FIND THREE INDICES SUCH THAT A[i]^2+A[j]^2=A[k]^2

//approach-sort the array and for each array compute A[i]^2 and store in array.
//tc-O(n^2)
//sc-O(1)

#include<iostream>
#include<algorithm>
using namespace std;

void threesum(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        arr[i]==arr[i]*arr[i];
    }

    int i=0;
    int j=n-1;
    
    while(i < j){
        if((arr[i] + arr[j])==target){
            cout<<arr[i]<<" "<<arr[j]<<" "<<target<<endl;
            return;
        }
        else if((arr[i] + arr[j])>target){
            j--;
        }
        else{
            i++;
        }
    }
    cout<<"does not exists";
}


int main(){
    int n;
    int target;
    cout<<"enter size of array";
    cin>>n;
    
    cout<<"enter target value";
    cin>>target;

    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    threesum(arr,n,target);
}
