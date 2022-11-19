/*Assume the two stacks are current: currentlevel and nextlevel. We would also need a variable to keep track 
 the current level order(whether it is left to right or right to left). We pop from the currentlevel stack and 
 print the nodes value. Whenever the current level order is from left to right, push the nodes left child, then 
 its right child to the stack nextlevel. Since a stack is a LIFO(Last-In-First_out) structure, next time when nodes
  are popped off nextlevel, it will be in the reverse order. On the other hand, when the current level order is
   from right to left, we would push the nodes right child first, then its left child. Finally, do-not forget to
    swap those two stacks at the end of each level(i.e., when current level is empty) 
*/
//approach1
//TC_O(n)
//SC_O(n)+O(n)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root)
            return ans;
        
        stack<TreeNode* > curr;
        stack<TreeNode* > next;
        
        bool lefttoright=true;
        
        curr.push(root);
        vector<int> v;
        while(!curr.empty()){
            TreeNode* temp=curr.top();
            curr.pop();
            v.push_back(temp->val);
            
            if(temp){
                if(lefttoright){
                    if(temp->left)
                        next.push(temp->left);
                    if(temp->right)
                        next.push(temp->right);
                }
                else{
                    if(temp->right)
                        next.push(temp->right);
                    if(temp->left)
                        next.push(temp->left);
                }
            }
            if(curr.empty()){
                ans.push_back(v);
                v.clear();
                lefttoright=!lefttoright;
                swap(curr,next);
            }
        }
        return ans;
    }
};