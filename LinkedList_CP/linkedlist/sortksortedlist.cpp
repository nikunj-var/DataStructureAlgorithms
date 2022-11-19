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
node* sort(node* head,int k){
    if(!head || !head->next){
        return head;
    }
    node* i=head;
    while(i){
        node* j=i;
        while(j->prev!=NULL && j->data < j->prev->data){
            node* temp=j->prev->prev;
            node* temp2=j->prev;
            node* temp3=j->next;
            j->prev->next=temp3;
            j->prev->prev=j;
            j->prev=temp;
            j->next=temp2;
            if(temp)
                temp->next=j;
            if(temp3)
                temp3->prev=temp2;
        }
        if(!j->prev)
            head=j;
    i=i->next;
    }
    return head;
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
    head= insertlinkedlist(head,1);
    head= insertlinkedlist(head,5);
    head= insertlinkedlist(head,2);
    head= insertlinkedlist(head,12);
    head= insertlinkedlist(head,4);
    head= insertlinkedlist(head,8);
    int k;
    cout<<"enter k";
    cin>>k;
    head=sort(head,k);
     print(head);

}