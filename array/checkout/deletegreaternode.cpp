//   Given a singly linked list, remove all the nodes which have a greater value on their right side.
  
//approach-reverse list
//traverse the list keep max till now if the nextnode is less than the max then delete the nextnode otherwise max=nextnode
//again reverse the list

    Node *reverse (Node *head)
    { 
        if(head == NULL || head->next==NULL)
            return head;
            
        Node* curr=head,*prev=NULL,*nextnode=NULL;
        
        while(curr!=NULL){
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        return prev;
    }

    
    Node *compute(Node *head)
    {
     if(!head || !head->next)
        return head;
        
       head=reverse(head);
       Node* current=head;
       Node* maxnode=head;
       
       while(current!=NULL && current->next!=NULL){
           if(current->next->data < maxnode->data){
               current->next=current->next->next;
           }
           else{
               current=current->next;
               maxnode=current;
           }
       }
       head=reverse(head);
       return head;
    }
};