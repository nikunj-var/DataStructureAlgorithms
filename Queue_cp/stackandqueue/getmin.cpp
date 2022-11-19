#include<iostream>
#include<stack>
using namespace std;

//In this article, a new approach is discussed that supports minimum with O(1) extra space. We define a variable minEle that stores the current minimum element in the stack. Now the interesting part is, how to handle the case when minimum element is removed. To handle this, we push “2x – minEle” into the stack instead of x so that the previous minimum element can be retrieved using the current minEle and its value stored in the stack. Below are detailed steps and an explanation of work.

// Push(x) : Inserts x at the top of stack. 

// If the stack is empty, insert x into the stack and make minEle equal to x.
// If the stack is not empty, compare x with minEle. Two cases arise:
// If x is greater than or equal to minEle, simply insert x.
// If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x. For example, let previous minEle was 3. Now we want to insert 2. We update minEle as 2 and insert 2*2 – 3 = 1 into the stack.
// Pop() : Removes an element from top of stack. 

// Remove element from top. Let the removed element be y. Two cases arise:
// If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
// If y is less than minEle, the minimum element now becomes (2*minEle – y), so update (minEle = 2*minEle – y). This is where we retrieve previous minimum from current minimum and its value in stack. For example, let the element to be removed be 1 and minEle be 2. We remove 1 and update minEle as 2*2 – 1 = 3.

class mystack{
    int mini;
    stack<int> st;
    public:
        void getmin(){
            if(st.empty())
            {
                cout<<"stack is empty"<<endl;
                return;
            }
            else{
                cout<<"minimum element is "<<mini<<endl;
            }
        }
        void push(int x){
            if(st.empty()){
                st.push(x);
                mini=x;
                cout<<"number inserted "<<x<<endl;  
                return;
            }
            else if(x < mini){
                st.push(2 * x - mini);
                mini=x;
            }
            else{
                st.push(x);
            }
            cout<<"number inserted "<<x<<endl;  
        }
        void pop(){
            if(st.empty()){
                cout<<"stack is empty"<<endl;
                return;
            }
           
                cout<<"top most element removed"<<endl;
                int t=st.top();
                st.pop();
                
                if(t < mini){
                    cout<<mini<<endl;
                    mini=2*mini - t;
                }
                else
                    cout<<t<<endl;
        }
};


int main(){
   
    mystack s;
    s.push(3);
    s.push(5);
    s.getmin();
    s.push(2);
    s.push(1);
    s.getmin();
    s.pop();
    s.getmin();
    s.pop();
    
}