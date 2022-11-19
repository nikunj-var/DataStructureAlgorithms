#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        queue<Node*> q;
        //vector<int> ans;
        q.push(node);
        q.push(NULL);
        int count=0;
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(temp==NULL){
                count++;
            }
          if(temp!=NULL){
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
           }
           else if(!q.empty())
                q.push(NULL);
           
        }
        return count;
    }
};