class Solution
{
    public:
    bool hasPathSum(Node *root, int key) {
        if(!root)
            return false;
        if(root->data == key && !root->left && !root->right)
            return true;
        return hasPathSum(root->left , key-root->data)|| hasPathSum(root->right , key-root->data);    
    }
};