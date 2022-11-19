#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    Node* divide(int N, Node *head){
        if(head == NULL)
            return NULL;
        Node* evenhead=NULL;
        Node* eventail=NULL,*oddhead=NULL,*oddtail=NULL;
        
        Node* temp=head;
        while(temp != NULL){
            if(temp->data % 2 == 0){
                if(evenhead == NULL){
                    evenhead=temp;
                    eventail=evenhead;
                }
                else{
                    eventail->next=temp;
                    eventail=eventail->next;
                }
            }
            else{
                if(oddhead == NULL){
                    oddhead=temp;
                    oddtail=oddhead;
                }
                else{
                    oddtail->next=temp;
                    oddtail=oddtail->next;
                }
            }
            temp=temp->next;
        }
        if(evenhead != NULL){
            eventail->next=oddhead;
            if(oddhead)
                oddtail->next=NULL;
            return evenhead;
        }
           return oddhead;
    }
};