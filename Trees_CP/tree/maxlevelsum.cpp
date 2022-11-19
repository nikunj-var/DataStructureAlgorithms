class Solution{
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) {
       int sum=0;
       int maxsum=INT_MIN;
       queue<Node*> q;
       q.push(root);
       q.push(NULL);
       
       while(!q.empty()){
           Node* temp=q.front();
           q.pop();
           
           if(!temp && !q.empty()) {
               q.push(NULL);
               maxsum=max(sum,maxsum);
               sum=0;
           }
           if(temp){
               sum+=temp->data;
               if(temp->left)
                q.push(temp->left);
               if(temp->right)
                q.push(temp->right);
           }
       }
       maxsum=max(sum,maxsum);
       return maxsum;
    }
};