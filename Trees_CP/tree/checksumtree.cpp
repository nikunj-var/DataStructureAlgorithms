class Solution
{
    public:
    pair<bool,int> check(Node* root,int sum){
        if(!root)
            return {true,0};
        if(!root->left && !root->right)
            return {true,root->data};
        auto f1=check(root->left,sum);
        auto f2=check(root->right,sum);
        
        if(!f1.first || !f2.first)
            return {false,-1};
        
        if(root->data != f1.second + f2.second)
            return {false,-1};
        
        sum=f1.second+f2.second+root->data;
        
        return {true,sum};
        
    }
    
    bool isSumTree(Node* root)
    {
        return check(root,0).first;
    }
};