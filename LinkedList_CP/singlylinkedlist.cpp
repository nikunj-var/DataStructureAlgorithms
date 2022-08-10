#include<iostream>
#include<stdlib.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int data){
            this->data=data;
            next=NULL;
        }
    //function to create linked list    
    node* insert(node* head,int data){
        node* newnode;
        newnode=new node(data);
        if(!newnode){
            cout<<"error";
            return head;
        }
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
        }
        else{
            node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    return head;
    }
    //function to insert at beginning
    node* insertatbeginning(node* head,int data){
        node* newnode=new node(data);
        if(head==NULL){
            head=newnode;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
        return head;
    }
    //function for insertatend
    node* insertatend(node* head,int data){
        node* newnode=new node(data);
        if(head==NULL){
            head=newnode;
        }
        else{
            node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
        return head;
    }
    //function for insertatspecificposition
    node* insertatpos(node* head,int data,int pos){
        node* newnode=new node(data);
        if(head==NULL){
            head=newnode;
        }
        else{
            int i=1;
            node* temp=head;
            while(i<pos-1){
                temp=temp->next;
                i++;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
        return head;
    }
    //function for deletefrombeginning
    node* deletefrombeg(node* head){
        if(head==NULL)
            return NULL;
        else{
            node*temp =head;
            head=head->next;
            free(temp);
        }    
        return head;
    }
    //function for deletefromend
    node* deletefromend(node* head){
        if(head==NULL)
            return NULL;
        else{
            node* temp =head;

              while(temp->next->next!=NULL){
                temp=temp->next;
            }
            node* prev=temp->next;
            temp->next=NULL;
            free(prev);
        }    
        return head;
    }
    //function for deletefromspecific position
    node* deletefrompos(node* head,int pos){
        if(head==NULL){
            head=NULL;
        }
        else{
            int i=1;
            node* temp=head;
            while(i<pos-1){
                temp=temp->next;
                i++;
            }
            node* prev=temp->next;
            temp->next=temp->next->next;
            free(prev);
        }
        return head;
    }
    void print(node* head){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    node *head=NULL;
    node* t;
    int pos;
    head= t->insert(head,10);
    head= t->insert(head,20);
    head= t->insert(head,30);
    head= t->insert(head,40);
    head= t->insert(head,50);
    head= t->insert(head,60);
    head= t->insertatbeginning(head,70);
    head= t->insertatend(head,100);
    head= t->insertatpos(head,1000,2);
    head= t->deletefrombeg(head);
    head= t->deletefromend(head);
    head= t->deletefrompos(head,2);
    t->print(head);
}