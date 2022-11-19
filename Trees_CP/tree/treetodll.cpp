// Algorithm:

// Traverse the tree in inorder fashion.
// While visiting each node, keep track of DLL’s head and tail pointers, insert each visited node to the end of DLL using tail pointer.
// Return head of the list.

class Solution
{
    public: 
    void converttodll(Node* root,Node*& head,Node*& tail){
        if(!root)
            return;
        converttodll(root->left,head,tail);
        
        if(head==NULL){
            head=root;
        }
        root->left=tail;
        if(tail){
            tail->right=root;
        }
        tail=root;
        converttodll(root->right,head,tail);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        if(!root)
            return NULL;
        Node* head=NULL;
        Node* tail=NULL;
        converttodll(root,head,tail);
        return head;
    }
};