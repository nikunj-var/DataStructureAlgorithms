#include<bits/stdc++.h>
using namespace std;
vector<int> reverseLevelOrder(Node *root)
{
    queue<Node*> q;
    stack<Node*> s;
    
        vector<int> ans;
        q.push(root);
        
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
           s.push(temp);
          
            if(temp->right)
                q.push(temp->right);
                
              if(temp->left)
                q.push(temp->left);    
        }
      while(!s.empty()){
          ans.push_back(s.top()->data);
          s.pop();
      }
        return ans;
}