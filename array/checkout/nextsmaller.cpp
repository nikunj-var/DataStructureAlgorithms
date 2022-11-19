
#include<iostream>
#include<stack>
using namespace std;


void nextsmaller(int arr[],int n,int ans[]){
    stack<int> st;
    
    st.push(-1);
    int i=n-1;
    ans[i]=-1;
    for(i;i>=0;i--){
         while(st.top() != -1 && st.top() >= arr[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";    
    }
}
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    int arr[n];
    cout<<"enter array elements ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans[n];
    nextsmaller(arr,n,ans);
    
}