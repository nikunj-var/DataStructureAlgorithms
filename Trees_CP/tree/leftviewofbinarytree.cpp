
#include<bits/stdc++.h>
using namespace std;



vector<int> leftView(Node *root)
{
   queue<Node*> q;
   q.push(root);
   q.push(NULL);
  
   vector<int> ans;
  
   if(root==NULL)
     return ans;
    
   ans.push_back(q.front()->data);
   
   while(!q.empty()){
       Node* temp=q.front();
       q.pop();
       if(temp==NULL && !q.empty()){
           
           ans.push_back(q.front()->data);
           temp=q.front();
           q.pop();
           
           if(!q.empty() || temp->left || temp->right){
               q.push(NULL);
           }
       }
       if(temp){
            if(temp->left)
              q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
       }
        
        if(q.empty())
            break;
   }
   return ans;
}
