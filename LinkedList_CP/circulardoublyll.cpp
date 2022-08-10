#include<iostream>
#include<stdlib.h>
using namespace std;

class node{
    public:
        int data;
        node* next,* prev;
        node(int data){
            this->data=data;
            next=NULL;
            prev=NULL;
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
            head->next=head;
            head->prev=head;
        }
        else{
            node* temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            newnode->prev=temp;
            temp->next=newnode;
            newnode->next=head;
            head->prev=newnode;
        }
    return head;
    }
    //function for insert at beginning
    node* insertatbeginning(node* head,int data){
        node* newnode;
        newnode=new node(data);
        if(!newnode){
            cout<<"error";
            return head;
        }
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            head->next=head;
            head->prev=head;
        }
        else{
            node* temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
           
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
            temp->next=newnode;
        }
    return head;
    }
    //function for insert at end
    node* insertatend(node* head,int data){
        node* newnode;
        newnode=new node(data);
        if(!newnode){
            cout<<"error";
            return head;
        }
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            head->next=head;
            head->prev=head;
        }
        else{
            node* temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            newnode->prev=temp;
            newnode->next=head;
            temp->next=newnode;
            head->prev=newnode;
        }
    return head;
    }
    //function for insert at specific position
    node* insertatpos(node* head,int data,int pos){
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
            int i=1;
            while(i<pos-1){
                temp=temp->next;
                i++;
            }
            newnode->next=temp->next;
            temp->next->prev=newnode;
            newnode->prev=temp;
            temp->next=newnode;
        }
    return head;
    }
    //function to delete from beginning
    node* deletefrombeg(node* head){
        if(head==NULL)
            return NULL;
        else{
            node*temp =head,*temp1=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            head=head->next;
            head->prev=temp;
            temp->next=head;
            
            free(temp1);
        }    
        return head;
    }
    //function to delete from end
    node* deletefromend(node* head){
        if(head==NULL)
            return NULL;
        else{
           node* temp=head,*temp1;
            while(temp->next->next!=head){
                temp=temp->next;
            }
            temp->next=head;
            head->prev=temp;
            // temp1=temp->next;
            // free(temp1);
        }    
        return head;
    }
    //function to delete from specific position
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
            temp->next->prev=temp->next;
            temp->next=temp->next->next;
            free(prev);
        }
        return head;
    }
    void print(node* head){
        node* temp=head;
        while(temp->next!=head){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data;
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