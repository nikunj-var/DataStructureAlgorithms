//INORDER TRAVERSAL WITHOUT RECURSION

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root )
            return ans;
        stack<TreeNode*> s;
        TreeNode* current=root;
        
        while(current!=NULL || !s.empty()){
            while(current!=NULL ){
                s.push(current);
                current=current->left;
            }    
            current=s.top();
            ans.push_back(s.top()->val);
            s.pop();
            current=current->right;
        }
        return ans;
    }
};

//INORDER TRAVERSAL USING RECURSION
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root){
             inorderTraversal(root->left);
             ans.push_back(root->val);
             inorderTraversal(root->right);
        }
        return ans;
    }
};