//IN THE ARRAY ALL ELEMENTS APPEAR TWICE OR FOUR TIMES ,EXCEPT ONE ELEMENT WHICH OCCUR THREE TIMES IN o(1)

//APPROACH-USING XOR
    //TC-O(N)
    //SC-O(1)

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

void findelement(int arr[],int n){
    int ans=arr[0];
    for(int i=1;i<n;i++){
        ans^=arr[i];
    }
    cout<<ans;
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    int n;
    int target;

    cout<<"enter size of array";
    cin>>n;
    
    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    findelement(arr,n);
    
}

//FIND THE LOCAL MINIMUM IN A ARRAY i.e-arr[i-1]<arr[i]<arr[i+1]

//APPROACH-find the mid if the mid follows the above condition then return it otherwise check in subarrays
    //TC-O(N)
    //SC-O(1)

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int findelement(int arr[],int low,int high){

        if(low > high)
            return -1;

        int mid=low+(high-low)/2;
        
        if( arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1])
            return mid;

        findelement(arr,low,mid-1);

        findelement(arr,mid+1,high);
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    int n;
    int target;

    cout<<"enter size of array";
    cin>>n;
    
    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"the local minimum is "<<arr[findelement(arr,0,n-1)];
    
}

//FIND THE MAXIMUM J-I ELEMENT SUCH THAT ARR[J]>ARR[I]

//APPROACH1-BRUTE FORCE
    //TC-O(N^2)
    //SC-O(1)

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

void findelement(int arr[],int n){
    int maxdiff=-1;

    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(arr[j]>arr[i]){
                maxdiff=max(maxdiff , j-i);
            }
        }
    }
    cout<<maxdiff;
}

int main(){
    int n;
    int target;

    cout<<"enter size of array";
    cin>>n;
    
    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    findelement(arr,n);
    
}


//APPROACH2-read book pageno-305
    //TC-O(N)
    //SC-O(n)

#include<iostream>
#include<stdlib.h>
#include<climits>
#include<algorithm>
using namespace std;

void findelement(int arr[],int n){
    int maxdiff=-1;
    int *leftarr=(int*)malloc(n*sizeof(int));
    int *rightarr=(int*)malloc(n*sizeof(n));

    leftarr[0]=arr[0];
    for(int i=1;i<n;i++){
        leftarr[i]=min(arr[i],leftarr[i-1]);
    }
    rightarr[n-1]=arr[n-1];
    for(int i = n-2; i >= 0; i--){
        rightarr[i]=max(arr[i],rightarr[i+1]);
    }
    int i=0,j=0;
    while(i < n && j < n){
        if(leftarr[i] < rightarr[j]){
            maxdiff=max(maxdiff , j-i);
            j++;
        }
        else{
            i++;
        }
    }
    cout<<maxdiff;
}

int main(){
    int n;
    int target;

    cout<<"enter size of array";
    cin>>n;
    
    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    findelement(arr,n);
    
}
