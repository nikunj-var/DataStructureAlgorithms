//to delete a tree first we have to delete its child nodes then delete parent nodes ,so to delete a tree do postorder traversal/

#include <bits/stdc++.h>
using namespace std;
 
// A tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// Utility function to create a new node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

//delete tree
void deletetree(Node* root){
    if(!root)
        return;
    deletetree(root->left);
    deletetree(root->right);
    delete root;    
}
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    cout << sum(root);
    return 0;
}