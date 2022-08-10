
//approach1-brute force
//tc-O(n^2)
//sc-O(1)

#include<iostream>
using namespace std;

void missingno(int arr[],int n){

    for(int i=1;i<=n;i++){
        int found=0;
        for(int j=0;j<n;j++){
            if(arr[j]==i){
                found=1;
                break;
            }
        }
        if(!found){
            cout<<i;
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

    missingno(arr,n);
}

//approach2->sort then scan
//tc-O(nlogn)
//sc-O(1)


#include<iostream>
#include<algorithm>
using namespace std;

void missingno(int arr[],int n){

    for(int i=1;i<=n;i++){
       if(arr[i-1]!=i){
            cout<<i;
            break;
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

    sort(arr,arr+n);
    
    missingno(arr,n);
}

// //approach3->using hashmap
// //tc-O(n)
// //sc-O(n)



#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

void missingno(int arr[],int n,unordered_map<int,int> mp){

    for(int i=1;i<=n;i++){
        if(mp[i]==0){
            cout<<i;
            break;
        }       
    }
}

int main(){
    int n;
    unordered_map<int,int> mp;

    cout<<"enter size of array";
    cin>>n;
    
    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    
    missingno(arr,n,mp);
}

//approach4->get sum of numbers n*(n+1)/2, and subtract all the numbers from sum ,missing number is remaining.
//tc-O(n)
//sc-O(1)

#include<iostream>
#include<algorithm>
using namespace std;

void missingno(int arr[],int n,int sum){

    for(int i=0;i<n;i++){
        sum-=arr[i];   
        cout<<sum<<" ";
    }

    cout<<endl<<sum;
}

int main(){
    int n;

    int sum=0;

    cout<<"enter size of array";
    cin>>n;
    
    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sum=((n+1)*(n+2))/2;
    cout<<"   "<<sum<<endl;
    missingno(arr,n,sum);
}

//approach3->using XOR:
            //i-XOR all the elements of the array,called X.
            //ii-XOR all numbers from 1 to n
            //iii-xor of x and y gives the missing  number
//tc-O(n)
//sc-O(1)

#include<iostream>
#include<algorithm>
using namespace std;

void missingno(int arr[],int n){

    int x,y;

    x=arr[0];
    for(int i=1;i<n;i++){
        x^=arr[i];
    }
    
    y=1;
    for(int i=2;i<=n+1;i++){
        y^=i;
    }

    int ans=x^y;
    cout<<ans;
}

int main(){
    int n;

    int sum=0;

    cout<<"enter size of array";
    cin>>n;
    
    int arr[n];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    missingno(arr,n);
}