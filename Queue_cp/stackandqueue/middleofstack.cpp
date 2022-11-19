#include<stack>
#include<deque>
#include<iostream>
using namespace std;

class mystack{
    public:
        stack<int> st;
        deque<int> q;

        void add(int data){
            q.push_back(data);
            if(q.size() > st.size() + 1){
                int temp=q.front();
                q.pop_front();
                st.push(temp);
            }
        }
        void pop(){
            int data=q.back();
            q.pop_back();   
             if(st.size() > q.size()){
                int temp=st.top();
                st.pop();
                q.push_front(temp);
            }        
        }
        int getmiddle(){
            return q.front();
        }
        void deletemiddle(){
            q.pop_front();
            if(st.size() > q.size()){
                int temp=st.top();
                st.pop();
                q.push_front(temp);
            }
        }
};

int main(){
    mystack s;
    s.add(1);
    s.add(2);
    cout<<"middle element "<<s.getmiddle()<<endl;
    s.add(3);
    s.add(4);
    s.add(5);
    cout<<"middle element "<<s.getmiddle()<<endl; 
    s.deletemiddle();
    cout<<"middle element "<<s.getmiddle()<<endl; 
    s.deletemiddle();
    cout<<"middle element "<<s.getmiddle()<<endl; 
    s.deletemiddle();
    s.pop();
    s.pop();
}