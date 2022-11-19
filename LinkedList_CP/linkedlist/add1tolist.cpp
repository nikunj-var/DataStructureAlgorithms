//add 1 to last node of the list
    

class Solution
{
    public:
    Node* reverse(Node *head)
    { 
       Node* curr=head,*prev=NULL,*nextnode=NULL;
       while(curr!=NULL){
           nextnode=curr->next;
           curr->next=prev;
           prev=curr;
           curr=nextnode;
       }
    
        return prev;
    }
    Node* addOne(Node *head) 
    {
        
        if(head==NULL)
            return head;
             
      head=reverse(head);
      int carry=1;
      Node* prev,*temp=head;
      
      while(temp!=0){
          if(carry){
              int data=temp->data+carry;
              temp->data=data%10;
              carry=data/10;
              prev=temp;
              temp=temp->next;
          }
          else{
              break;
          }
      }
      if(carry > 0){
          Node* newnode=new Node(carry);
          prev->next=newnode;
      }
      
      head=reverse(head);
      
      return head;
    }
};
