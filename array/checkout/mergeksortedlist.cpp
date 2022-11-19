class comapare{
    public:
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
};
class Solution {
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*>,comapare> minheap;
        ListNode *head=NULL,*tail=NULL;
        int k=lists.size();
        if(k==0)
            return NULL;
        for(int i=0;i<k;i++){
            if(lists[i])
                minheap.push(lists[i]);
        }
        while(minheap.size()>0){
            ListNode* temp=minheap.top();
            minheap.pop();
            if(head==NULL){
                head=temp;
                tail=temp;
            }
            else{
                tail->next=temp;
                tail=tail->next;
            }
            if(tail->next){
                minheap.push(tail->next);
            }
        }
        return head;
    }
};