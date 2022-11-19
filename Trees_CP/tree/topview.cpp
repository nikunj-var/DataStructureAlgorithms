 #include<bits/stdc++.h>
using namespace std;
 
 vector<int> topView(Node *root)
    {
        map<int,int> m;
        queue<pair<Node* ,int>> q;
        
        vector<int > ans;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int > temp = q.front();
            q.pop();
            Node* topnode=temp.first;
            int hd=temp.second;
            
            if(m.find(hd)==m.end())
                m[hd]=topnode->data;
            
            if(topnode->left)
                q.push(make_pair(topnode->left,hd-1));
            if(topnode->right)
                q.push(make_pair(topnode->right,hd+1));
            
        }
        for(auto i:m)
            ans.push_back(i.second);
        return ans;
    }