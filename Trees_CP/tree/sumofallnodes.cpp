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

//by recursion
int sum(Node* root){
    if(!root)
        return 0;
    return root->data + sum(root->left) + sum(root->right);    
}

//by iteration
int sum(Node* root){
    int ans=0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        ans+=temp->data;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp-right);    
    }
    return ans;
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