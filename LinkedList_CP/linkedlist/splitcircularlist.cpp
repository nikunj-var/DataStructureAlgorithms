//function to split circular linked into two halves

void splitList(Node *head, Node **head1, Node **head2)
{
    Node* slow=head,*fast=head;
   
    while(fast->next!=head && fast->next->next!=head ){
       // cout<<slow->data<<" "<<fast->data;
        slow=slow->next;
        fast=fast->next->next;
    }
    
     *head2=slow->next;
     
     if(fast->next == head)
         fast->next=slow->next;
     
     if(fast->next ->next== head)
         fast->next->next=slow->next;
     
     slow->next=head;
   
    *head1=head;
    
}