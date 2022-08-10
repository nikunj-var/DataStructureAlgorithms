// we have given an array we have to check whether there is any duplicate in the array or not

// approach1->using two for loops
// tc-O(n^2) 
// sc->O(1)

#include<iostream>
using namespace std;

bool checkduplicate(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j])
                return true;
        }
    }
    return false;
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

    if(checkduplicate(arr,n))
        cout<<"duplicate exists";
    else
        cout<<"not exists";    

}


// approach2->sort array then scan
// tc->O(nlogn)
// sc->O(1)

#include<iostream>
#include<algorithm>
using namespace std;

bool checkduplicate(int arr[],int n){
    for(int i=0;i<n-1;i++){
       if(arr[i]==arr[i+1])
        return true;
    }
    return false;
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

    if(checkduplicate(arr,n))
        cout<<"duplicate exists";
    else
        cout<<"not exists";    

}

// approach3->using hashmap
// tc->O(n)
// sc->O(n)

#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool checkduplicate(int arr[],int n,unordered_map<int,int> m){
    for(int i=0;i<m.size();i++){
       if(m[i] > 1)
        return true;
    }
    return false;
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

    unordered_map<int,int> m;

    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }

    if(checkduplicate(arr,n,m))
        cout<<"duplicate exists";
    else
        cout<<"not exists";    

}


// approach4->//assume all the array elements are positive and in the range of 0 to n-1
//             for each element go to array element whose index is A[A[i]] and mark it is as negative
//             if there is any duplicate availabe then that element is already encountered.
// tc->O(n)
// sc->O(1)

#include<iostream>
using namespace std;

bool checkduplicate(int arr[],int n){
   for(int i=0;i<n;i++){
        if(arr[abs(arr[i])]<0){
            return true;
        }
        else{
            arr[arr[i]]=-arr[arr[i]];
        }
   }
   return false;
}

int main(){
    int n;
    
    cout<<"enter size of array";
    cin>>n;
    
    int arr[n];
    cout<<"enster array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(checkduplicate(arr,n))
        cout<<"duplicate exists";
    else
        cout<<"not exists";    

}