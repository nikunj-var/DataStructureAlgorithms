class Solution{
    public:
  
    pair<bool,int> balance(Node* root){
        pair<bool,int> p;
        if(root == NULL)
        {
            p=make_pair(true,0);
            return p;
        }
        pair<bool,int> left=balance(root->left);
        pair<bool,int> right=balance(root->right);
        bool diff=abs(left.second-right.second) <= 1;
        
        p.second=max(left.second,right.second)+1;
        if(left.first && right.first && diff){
            p.first=true;
        }
        else
            p.first=false;
            
        return p;
    }
    bool isBalanced(Node *root)
    {
       pair<bool,int> p=balance(root);
       if(p.first)
            return true;
        return false;
        
    }
};
