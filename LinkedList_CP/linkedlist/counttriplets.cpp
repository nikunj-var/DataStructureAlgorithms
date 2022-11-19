// Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value x, without using any extra space? 

//creation of linked list
#include<iostream>
#include<stdlib.h>
using namespace std;
class node{
   
    public:
         int data;
        node* next=0;
        node* prev=0;
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
        newnode->prev=temp;
        temp->next=newnode;
    }
    return head;
}

void counttriplets(node* head,int target){
    node* first=head,*second=head;
    bool found=false;
    while(second->next != NULL){
        second=second->next;
    }
    node* tail=second;
    node* temp=head;
    while(temp->next->next->next != NULL){
        first=temp->next;
        second=tail;
        while(first != second && second->next!=first){
            if(temp->data + first->data + second->data == target){
                cout<<endl<<temp->data<<" "<<first->data<<" "<<second->data<<endl;
                found=true;
                break;
            }
            else if(temp->data + first->data + second->data < target){
                 first=first->next;
            }
            else{
                second=second->prev;
            }
        }
        temp=temp->next;
    }
    if(!found)
        cout<<"no pair exists";
    }



void print(node *head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
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
    counttriplets(head,120);
     print(head);

}