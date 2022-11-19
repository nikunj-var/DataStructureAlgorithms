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
    
    Node* insertatend(Node* head,int data){
        
    Node *newnode;
    newnode=new Node(data);
    newnode->next=0;
    if(head==NULL){
        head=newnode;
    }
    else{
        Node* temp;
        temp=head;
        while(temp->next!=0){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
    
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {   
        if(first==NULL)
            return second;
        if(second==NULL)
            return first;
        
        first=reverse(first);
        second=reverse(second);
        
        Node* head=NULL;
        Node* temp1=first,*temp2=second;
        
        int carry=0;
        
        while(temp1!=NULL && temp2!=NULL){
            int sum=temp1->data + temp2->data + carry;
           
            carry=sum/10;
            sum=sum%10;
            
            temp1=temp1->next;
            temp2=temp2->next;
            
            head=insertatend(head,sum);
        }
        
        while(temp1!=NULL){
            int sum=temp1->data + carry;
           
            carry=sum/10;
            sum=sum%10;
            
            temp1=temp1->next;
            
            head=insertatend(head,sum);
        }
         while(temp2!=NULL){
            int sum=temp2->data + carry;
           
            carry=sum/10;
            sum=sum%10;
            
            temp2=temp2->next;
            
            head=insertatend(head,sum);
        }
        
        if(carry > 0){
            head=insertatend(head,carry);
        }
        
        head=reverse(head);
        
        return head;
    }
};