
class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        if(!root)
            return true;
        queue<Node* > q;
        q.push(root);
        int level=0;
        int ans=INT_MAX;
        while(!q.empty()){
            level++;
            int s=q.size();
            while(s > 0){
                auto temp=q.front();
                  q.pop();
                if(temp->left){
                    q.push(temp->left);
                    if(!temp->left->left && !temp->left->right){
                        if(ans == INT_MAX)
                            ans=level;
                        else if(ans != level)
                            return false;
                    }
                }
                 if(temp->right){
                    q.push(temp->right);
                    if(!temp->right->left && !temp->right->right){
                        if(ans == INT_MAX)
                            ans=level;
                        else if(ans != level)
                            return false;
                    }
                }
                s--;
            }
           
        }
        return true;
    }
};
