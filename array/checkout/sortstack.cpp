#include<iostream>
#include<stack>
using namespace std;

void sortstack(stack<int>& st,int n){
    stack<int> tempstk;

    while(!st.empty()){
        int val=st.top();
        st.pop();

        while(!tempstk.empty() && tempstk.top() > val){
            st.push(tempstk.top());
            tempstk.pop();
        }
        
        tempstk.push(val);
    }
    cout<<"sorted stack:"<<endl;
    while(!tempstk.empty()){
        cout<<tempstk.top()<<" ";
        tempstk.pop();
    }

}

int main(){
    stack<int> st;
    int n;
    cout<<"enter n";
    cin>>n;
   
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        st.push(a);
    }
    sortstack(st,n);

}