//SEPARATE EVEN AND ODD NUMBERS 


//approach-DUTCH NATIONAL FLAG ALGORITHM
// i-INITIALIZE TWO INDEX VARIABLES LEFT AND RIGHT : LEFTO=0,RIGHT=N-1
// ii-KEEP INCREMENTING THE LEFT INDEX UNTIL YOU SEE AN ODD NUMBER
// iii-KEEP INCREMENTING THE RIGHT INDEX UNTIL YOU SEE AN EVEN NUMBER
//IF LEFT<RIGHT SWAP BOTH THE NUMBERS

//tc-O(n)
//sc-O(1)
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

void separateevenodd(int arr[],int n){
    int left=0;
    int right=n-1;

    while(left < right){
        while(arr[left]%2 == 0 && left < right)
        {
            left++;
        }

        while(arr[right]%2 == 1 && left < right)
        {
            right--;
        }

        if(left < right){
            //swap 
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
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

    separateevenodd(arr,n);
    printarray(arr,n);
}

//SEPARATE 0's AND 1's IN A ARRAY

//approach1-count the number of 0's and 1's
//tc-O(n)
//sc-O(1)

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

void separate01(int arr[],int n){
    int count0=0;
    int count1=0;

    for(int i=0;i<n;i++){
        if(arr[i]==0)
            count0++;
        else
            count1++;    
    }
    int i=0;
    while(i<count0){
        arr[i]=0;
        //cout<<i<<endl;
        i++;
    }
    
    int j=0;
    while(j<count1){
        arr[j+i]=1;
        j++;
    }
        
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

    separate01(arr,n);
    printarray(arr,n);
}

//approach2-use two pointer approach
//tc-O(n)
//sc-O(1)

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

void separate01(int arr[],int n){
    int i=0;
    int j=n-1;
    while(i < j){
        while(arr[i] == 0 && i < j){
            i++;
        }
        while(arr[j] == 1 && i < j){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
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

    separate01(arr,n);
    printarray(arr,n);
}

//SEPARATE AND SORT 0's , 1's and 2's

//approach2-use three pointer approach
//tc-O(n)
//sc-O(1)

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

void separate012(int arr[],int n){
    int i=0;
    int mid=0;
    int j=n-1;
    while(mid <= j){
        switch(arr[mid]){
            case 0:swap(arr[i],arr[mid]);
                    i++;
                    mid++;
                    break;
            case 1:mid++;
                   break;
            case 2:swap(arr[mid],arr[j]);
                    j--;
                    break;       
        }
    }
        
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

    separate012(arr,n);
    printarray(arr,n);
}