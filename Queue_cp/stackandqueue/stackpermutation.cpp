#include<iostream>
#include<stack>
using namespace std;

// Idea –  we will start iterating on input array and storing its element one by one in a stack and if top of our stack matches with an element in output array we will pop that element from stack and compare next element of output array with top of our stack if again it matches then again pop until our stack isn’t empty 

bool checkpermutation(int in[],int out[],int n){
    stack<int> st;
    int j=0;
    for(int i=0;i<n;i++){
        st.push(in[i]);

        while(!st.empty() && st.top() == out[j]){
            st.pop();
            j++;
        }
    }
    if(st.empty())
        return true;
    return false;    
}


int main(){
    
    int n;
    cout<<"enter n";
    cin>>n;
    int in[n],out[n];
    cout<<"enter input array";
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    cout<<"enter output array";
    for(int i=0;i<n;i++){
        cin>>out[i];
    }
    
    cout<<checkpermutation(in,out,n);

}