#include<iostream>
#include<stack>
using namespace std;

void nextgreater(int arr[],int n){
    int ans[n];
    ans[n-1]=-1;
    stack<int> st;
    st.push(-1);
   
    for(int i=n-1;i>=0;i--){
        
        while(st.top() != -1 && st.top() <= arr[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<"next greater element of "<<arr[i]<<"is "<<ans[i]<<endl;
    }
}

int main(){
    
    int n;
    cout<<"enter n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    nextgreater(arr,n);

}