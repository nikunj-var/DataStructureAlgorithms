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
        
    }
    else{
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        
    }
    return head;
}

node* insertionsort(node* head){
    node* dummy=new node(1000);
    while(head){
        node* temp=dummy;
        node* nextn=head->next;
        while(temp->next && temp->next->data < head->data){
            temp=temp->next;
        }
        head->next=temp->next;
        temp->next=head;
        head=nextn;
    }
    return dummy->next;
}

void print(node *head){
    node* temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<temp->data;
}
int  main(){
    node *head=NULL;
    int pos;
    head= insertlinkedlist(head,10);
    head= insertlinkedlist(head,3);
    head= insertlinkedlist(head,4);
    head= insertlinkedlist(head,1);
    head= insertlinkedlist(head,90);
    head= insertlinkedlist(head,89);
    head=insertionsort(head);
    print(head);

}