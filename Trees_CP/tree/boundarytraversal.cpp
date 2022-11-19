/*Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root. The boundary includes left boundary, leaves, and right boundary in order without duplicate nodes. (The values of the nodes may still be duplicates.)
The left boundary is defined as the path from the root to the left-most node. The right boundary is defined as the path from the root to the right-most node. If the root doesn’t have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not apply to any subtrees.
The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if it exists. If not, travel to the right subtree. Repeat until you reach a leaf node.
The right-most node is also defined in the same way with left and right exchanged. 

We break the problem in 3 parts: 

1. Print the left boundary in top-down manner. 
2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts: 
…..2.1 Print all leaf nodes of left sub-tree from left to right. 
…..2.2 Print all leaf nodes of right subtree from left to right. 
3. Print the right boundary in bottom-up manner.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void leftview(Node *root,vector<int>& ans)
{
    if(root == NULL)
        return;
    if(root->left)
    {
        ans.push_back(root->data);
        leftview(root->left,ans);
    }
    else if(root->right){
        ans.push_back(root->data);
        leftview(root->right,ans);
    }
   
}

void rightview(Node* root,vector<int>& ans){
   if(!root)
    return;
    
    if(root->right){
        rightview(root->right,ans);
                ans.push_back(root->data);
    }
    else if(root->left){
   
        rightview(root->left,ans);
             ans.push_back(root->data);
    }

}
void leafpart(Node* root,vector<int>& ans){
    if(root==NULL)
        return ;
    leafpart(root->left,ans);
    if(!root->left && !root->right){
             ans.push_back(root->data);
    }
    leafpart(root->right,ans);    
}
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root->data);
        leftview(root->left,ans);
        leafpart(root->left,ans);
        leafpart(root->right,ans);
        rightview(root->right,ans);
        return ans;
    }
};