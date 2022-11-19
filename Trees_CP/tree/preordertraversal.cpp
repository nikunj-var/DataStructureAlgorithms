//PREORDER TRAVERSAL WITHOUT RECURSION

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
            return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            ans.push_back(st.top()->val);
            TreeNode* curr=st.top();
            st.pop();
            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);
        }
        return ans;
    }
};

//PREORDER TRAVERSAL WITH RECURSION
class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root){
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        }
        return ans;
    }
};