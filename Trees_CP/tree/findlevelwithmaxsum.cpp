class Solution{
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) {
       int sum=0;
       int maxlevel=-1;
       int maxsum=INT_MIN;
       queue<Node*> q;
       q.push(root);
       q.push(NULL);
        int level=0;
       while(!q.empty()){
           Node* temp=q.front();
           q.pop();
           
           if(!temp ) {
            if(!q.empty())
               q.push(NULL);
               if(sum > maxsum){
                maxsum=sum;
                maxlevel=level;
               }
               sum=0;
               level++;
           }
           if(temp){
               sum+=temp->data;
               if(temp->left)
                q.push(temp->left);
               if(temp->right)
                q.push(temp->right);
           }
       }
     
       return maxlevel;
    }
};