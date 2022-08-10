#include<iostream>
using namespace std;

#define max 100

class deque{
    int arr[max];
    int front;
    int rear;
    int size;
    public:
        deque(int size){
            this->size=size;
            front=-1;
            rear=-1;
        }
        void insertfront(int d){
            if(size>=max){
                cout<<"overflow"<<endl;
                return;
            }
            if(front==-1){
                front=0;
                rear=0;
            }
            else if(front == 0){
                front=size-1;
            }
            else{
                front=front-1;
            }

            arr[front]=d;
        }
        void insertrear(int d){
            if(size>=max){
                cout<<"overflow"<<endl;
                return;
            }
            if(front==-1){
                front=0;
                rear=0;
            }
            else if(rear==size-1){
                rear=0;
            }
            else{
                rear=rear+1;
            }
            arr[rear]=d;
        }
        void deletefront(){
            if(front==-1){
                cout<<"underflow"<<endl;
                return;
            }
            if(front==rear)
            {
                front=-1;
                rear=-1;
            }
            else if(front==size-1){
                front=0;
            }
            else{
                front=front+1;
            }
        }
        void deleterear(){
            if(front==-1){
                cout<<"underflow"<<endl;
                return;
            }
            if(front==rear){
                front=-1;
                rear=-1;
            }
            else if(rear==0){
                rear=size-1;
            }
            else{
                rear=rear-1;
            }
        }
        int getfront(){
            if(front==-1){
                cout<<"queue is empty";
                return -1;
            }
            return arr[front];
        }
        int getrear(){
            if(rear==-1){
                cout<<"queue is empty";
                return -1;
            }
            return arr[rear];
        }
        bool isfull(){
            return ((front==0 && rear==max-1)||front==rear+1);
        }
        bool isempty(){
            return (front==-1);
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
    deque *q=new deque(10);
    q->insertfront(10);
    q->insertfront(20);
    q->insertrear(30);
    q->insertrear(40);
    q->print();
}