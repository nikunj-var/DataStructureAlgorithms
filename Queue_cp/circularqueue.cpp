#include<iostream>
#include<stdlib.h>
using namespace std;

class circularqueue{
    public:
        int front;
        int rear;
        int size;
        int *arr;
        circularqueue(int s){
            front=rear=-1;
            size=s;
            arr=(int*)malloc(size*sizeof(int));
        }
        void enqueue(int value){
            if((front==0 && rear==size-1) || (front-1)%(size-1)==rear){
                cout<<"queue is full";
                return;
            }
            else if(front==-1){
                front=rear=0;
            }
            else if(front!=0 && rear==size-1){
                rear=0;
            }
            else{
                rear=rear+1;
            }
            arr[rear]=value;
        }   
        void dequeue(){
            if(front==-1){
                cout<<"queue is empty";
                return;
            }
            if(front==rear){
                front=-1;
                rear=-1;
            }
            else if(front == size-1){
                front=0;
            }
            else{
                front=front+1;
            }
        }
        int getfront(){
            if(front==-1)
                return -1;
            return arr[front];    
        }
        void print(){
            int i=front;
            while(i!=rear){
                cout<<arr[i]<<" ";
                i=(i+1)%size;
            }
            cout<<arr[i];
        }
};

int main(){
    circularqueue *q=new circularqueue(20);
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->dequeue();
    q->enqueue(40);
    q->enqueue(50);
    q->enqueue(60);
    q->enqueue(70);
    cout<<q->getfront()<<endl;
    q->print();
    
}