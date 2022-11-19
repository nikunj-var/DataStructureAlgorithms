class Solution{
  public:
    Node* merge(Node* left,Node* right){
        if(!left)
            return right;
        if(!right)
            return left;
        
        Node* ans=new Node(-1);
        Node* temp=ans;
        
        while(left && right){
            if(left->data < right->data ){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
            }
        }
    
        while(left){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        while(right){
            temp->next=right;
            temp=right;
            right=right->next;
        }
        return ans->next;
    }
    Node* findmid(Node* head){
        Node* slow=head;
        Node* fast=head->next;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(!head || !head->next)
            return head;
        
        Node* mid=findmid(head);
        Node* left=head;
        Node* right=mid->next;
        mid->next=NULL;
        
        left=mergeSort(left);
        right=mergeSort(right);
        
        Node* result=merge(left,right);
        return result;
    }
};
