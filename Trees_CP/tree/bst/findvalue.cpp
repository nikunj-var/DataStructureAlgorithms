// Function to search a node in BST.
bool search(Node* root, int x) {
    if(!root)
        return false;
    if(root->data == x)
        return true;
    if(root->data > x)
        return search(root->left,x);
    return search(root->right,x);    
}

TC-O(height of tree)
SC-O(n)