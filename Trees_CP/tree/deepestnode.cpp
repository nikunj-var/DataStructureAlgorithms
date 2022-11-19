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

Node* deepestNode(Node* root){
    queue<Node*> q;
    if(!root)
        return NULL;
    q.push(root);
    Node* temp;
    while(!q.empty()){
        temp=q.front();
        q.pop();

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);    
    }    
    return temp;
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
    cout << deepestNode(root)->data;
    return 0;
}