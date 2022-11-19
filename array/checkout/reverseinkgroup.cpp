#include<bits/stdc++.h>
using namespace std;



struct node *reverse (struct node *head, int k)
    { 
        if(head == NULL || head->next==NULL)
            return head;
            
        node* curr=head,*prev=NULL,*nextnode=NULL;
        int count=0;
        while(curr!=NULL && count<k){
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
            count++;
        }
        
        if(nextnode != NULL)
            head->next=reverse(nextnode,k);
            
        return prev;
            
    }

