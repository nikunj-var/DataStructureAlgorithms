#include<iostream>
#include<stdlib.h>
using namespace std;

//IMPLEMENTATON USING ARRAYS
class queue{
    int capacity;
    int rear,front;
    int* arr;
    
public:
    queue(int c){
        rear=0;
        front=0;
        capacity=c;
        arr=new int;
    }
    void enqueue(int data){
        if(rear==capacity)
        {
            cout<<"overflow";
            return;
        }
        else{
            arr[rear]=data;
            rear++;
            cout<<"inserted"<<endl;
        }
    }
    void dequeue(){
        if(front==rear){
            cout<<"underflow"<<endl;
            return;
        }
        else{
            for(int i=0;i<rear-1;i++){
                arr[i]=arr[i+1];
            }
            rear--;
            cout<<"deleted"<<endl;
        }
    }
    int getfront(){
        if(rear==0)
            return -1;
        return arr[front];    
    }
    int isempty(){
        if(front==rear)
            return 1;
        return 0;    
    }
    int isfull(){
        if(rear==capacity)
            return 1;
        return 0;    
    }
    void print(){
        int i=0;
        for(i=0;i<rear;i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    queue *q=new queue(100);
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(10);
    q->enqueue(20);
    q->dequeue();
    q->print();
    cout<<endl<<q->getfront();
    cout<<endl<<q->isempty();
    cout<<endl<<q->isfull();
}

// IMPLEMENTATION USING LINKEDLIST

class queue{
    public:
        int data;
        queue* front;
        queue* rear;
        queue* next;
        queue(){
            front=NULL;
            rear=NULL;
            next=NULL;
        }
        void enqueue(int data){
            queue* newnode=new queue();
            newnode->data=data;
            if(front==NULL){
                front=newnode;
                rear=front;
            }
            else{
                rear->next=newnode;
                rear=rear->next;
            }
            cout<<"inserted";
        }
        void dequeue(){
            if(front==NULL){
                cout<<"queue is empty";
                return;
            }
            else{
                queue* temp=front;
                front=front->next;
                free(temp);
            }
        }
        void print(){
            queue* temp;
            temp=front;
            while(temp!=rear){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<" "<<temp->data;
        }
};
int main(){
    queue* q=new queue();
    q->enqueue(20);
     q->enqueue(30);
      q->enqueue(40);
       q->enqueue(50);
       q->print();
       q->dequeue();
       cout<<q->front->data;

}