//REMOVE DUPLICATE NODE FROM A SORTED LIST

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next=NULL;
};

Node *removeDuplicates(Node *head)
{
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->data==temp->next->data){
            temp->next=temp->next->next;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}

//REMOVE DUPLICATE NODES FROM AN UNSORTED LIST

    Node * removeDuplicates( Node *head) 
    {   
        if(head==NULL || head->next==NULL)
            return head;
        
        Node* temp=head;
        
        Node* prev;
        unordered_map<int,int> mp;
        
        while(temp != NULL){
           
            if(mp[temp->data]==0){
                mp[temp->data]=1;
                prev=temp;
            }
            else{
                prev->next=temp->next;
            }
            
            temp=temp->next;
        }
        return head;
    }