#include<iostream>
#include<stdlib.h>
using namespace std;

class stack{
    int top;
   
    public:
        int arr[1000];
        stack(){
            top=-1;
        }
        bool push(int d){
            if(top>=1000-1){
                cout<<"stack overflow"<<endl;
                return false; 
            }
            else{
                arr[++top]=d;
                return true;
            }
        } 
        bool pop(){
            if(top==-1){
                cout<<"stack underflow";
                return false;
            }
            else{
             
                int x=arr[top--];
            }
            return true;
        }
        int peek(){
            if(top<0){
                cout<<"stack underflow"<<endl;
                return -1;
            }
            return arr[top];
        }
        void printstack(){
            int i=top;
            while(i){
                cout<<arr[i]<<" ";
                i--;
            }
            cout<<arr[i]<<endl;
        }
        bool isempty(){
            if(top==-1)
                return true;
            return false;    
        }
        bool isfull(){
            if(top>=1000-1)
                return true;
            return false;    
        }

};


//STACK IMPLEMENTATION USING LINKED LIST
class node{
    public:
        int data;
        node* next;
};
node* top=NULL;
void push(int data){
    node* temp=new node();
    if(!temp){
        cout<<"stack overflow";
        return;
    }
    temp->data=data;
    temp->next=top;
    top=temp;
}
int isempty(){
    if(top==NULL)
        return 1;
    return 0;    
}
int peek(){
    if(top==NULL)
        return -1;
    return top->data;    
}
void pop(){
    node* temp;
    if(!top){
        cout<<"stack underflow";
        return;
    }
    else{
        temp=top;
        top=top->next;
        free(temp);
    }
}
void display(){
    node* temp;
    if(!top){
        cout<<"stack overflow"<<endl;\
        return;
    }
    else{
        temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    cout<<endl;
}
int main(){
    // stack s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);
    // s.printstack();
    // cout<<s.peek();
    // cout<<endl<<s.isempty();
    // cout<<endl<<s.isfull();

    push(10);
     push(20);
     push(30);
     push(40);
     push(50);
     display();
     pop();
    
}