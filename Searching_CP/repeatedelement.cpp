//IN A ARRAY ALL THE ELEMENTS OCCUR ONLY ONCE EXCEPT TWO ELEMENTS FIND THOSE ELEMENTS.


//approach1-brute force
//tc-O(n^2)
//sc-O(1)
#include<iostream>
using namespace std;

void twotimeoccurence(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                cout<<arr[i]<<endl;
                break;
            }
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

    twotimeoccurence(arr,n);
}

//approach2-sort array then scan
//tc-O(nlogn)
//sc-O(1)


#include<iostream>
#include<algorithm>
using namespace std;

void twotimeoccurence(int arr[],int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1])
            cout<<arr[i]<<endl;
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

    sort(arr,arr+n);

    twotimeoccurence(arr,n);
}


//approach3-create a count array of size n if the count[i]==2 print it
//tc-O(n)
//sc-O(n)


//approach4-using XOR
//tc-O(n)
//sc-O(n)

// #include<iostream>
// #include<algorithm>
// using namespace std;

// void twotimeoccurence(int arr[],int n){
    
//     int =arr[0];
//     int x,y;

//     for(int i=0;i<n;i++){

//     }

// }

// int main(){
//     int n;
    
//     cout<<"enter size of array";
//     cin>>n;
    
//     int arr[n];
//     cout<<"enter array";
    
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     twotimeoccurence(arr,n);
// }