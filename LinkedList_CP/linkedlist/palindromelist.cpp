class Solution {
    private:
    ListNode *getmid(ListNode *head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode *curr=head,*prev=NULL,*nextn=NULL;
        while(curr!=NULL){
            nextn=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextn;
        }
        return prev; 
        
        
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
            return true;
        if(head->next->next==NULL){
            if(head->val==head->next->val)
                return true;
            else
                return false;
        }
        //step1  find middle
        ListNode* middle=getmid(head);
        ListNode *temp=middle->next;
        
        //step2->reverse list after middle
        middle->next=reverse(temp);
        
        //step3->compare both halves
        ListNode *head2=middle->next;
        ListNode* head1=head;
        
        while(head2!=NULL){
            if(head1->val!=head2->val)
                return false;
            head1=head1->next;
            head2=head2->next;
        
        }
        temp=middle->next;
        middle->next=reverse(temp);
        return true;
    }
};