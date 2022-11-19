#include<iostream>
#include<stdlib.h>
using namespace std;
class node{
   
    public:
         int data;
        node* next=0;
        node(int data){
            this->data=data;
        }
};
node* insertlinkedlist( node *head,int data){
    
    node *newnode;
    newnode=new node(data);
    if(!newnode){
        cout<<"node not created"<<endl;
        return head;
    }
    newnode->next=0;
    if(head==NULL){
        head=newnode;
        head->next=head;
    }
    else{
        node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
    return head;
}

node* reverse(node* head){
    node* temp=head;
    node* nextnode=NULL,*prev=NULL,*curr=head;
    do{
        nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }while(curr!=head);

    head->next=prev;
    head=prev;
    return head;
}

void print(node *head){
    node* temp=head;
    while(temp->next!=head){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<temp->data;
}
int  main(){
    node *head=NULL;
    int pos;
    head= insertlinkedlist(head,10);
    head= insertlinkedlist(head,20);
    head= insertlinkedlist(head,30);
    head= insertlinkedlist(head,40);
    head= insertlinkedlist(head,50);
    head= insertlinkedlist(head,60);
    head=reverse(head);
    print(head);

}