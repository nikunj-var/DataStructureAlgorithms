#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next=NULL;
}

int findbeginofloop(Node* head){
    int loopexists=0;
    Node* fast=head->next,*slow=head;
        while(fast && fast->next){
            if(fast == slow)
            {
                loopexists=1;
                break;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        if(loopexists){
            slow=head;
            while(slow != fast){
                fast=fast->next;
                slow=slow->next;
            }
            return slow->data;
        }
        
    return -1;
}