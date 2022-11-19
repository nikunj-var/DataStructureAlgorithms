class compare{
    public:
        bool operator()(Node* a,Node* b){
            return a->data > b->data;
        }
};
class Solution{
  public:

    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k)
    {
           priority_queue<Node* , vector<Node*> ,compare>  q;
           
           for(int i=0;i<k;i++){
               q.push(arr[i]);
           }
           
           Node* head=NULL,*tail=NULL;
           
           while(!q.empty()){
               auto temp=q.top();
               q.pop();
               if(head == NULL){
                   head=tail=temp;
               }
               else{
                   tail->next=temp;
                   tail=temp;
               }
               if(tail->next)
                    q.push(tail->next);
           }
        return head;
    }
};