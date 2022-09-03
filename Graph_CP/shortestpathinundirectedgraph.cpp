#include<bits/stdc++.h>
using namespace std;

//using bfs
vector<int> path(vector<int> adj[],int s,int t){
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;

    queue<int> q;
    q.push(s);
    parent[s]=-1;
    visited[s]=true;

    while(!q.empty()){
        int front=q.front();
        q.pop();

        for(auto i:adj[front]){
            if(!visited[i]){
                visited[i]=true;
                parent[i]=front;
                q.push(i);
            }
        }
    }
    vector<int> ans;
    int currnode=t;
    while(currnode != s){
        currnode=parent[currnode];
        ans.push_back(currnode);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}