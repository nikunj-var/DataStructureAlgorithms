#include<bits/stdc++.h>
using namespace std;

//using bfs

class Solution {
  public:
    bool iscycle(int node,unordered_map<int,bool> &visited,vector<int> adj[]){
        unordered_map<int,int> parent;
        parent[node]=-1;
        queue<int> q;
        q.push(node);
        visited[node]=true;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto i:adj[front]){
                if(visited[i] == true && i != parent[front])
                    return true;
                else if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                    parent[i]=front;
                }    
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        unordered_map<int,bool> visited;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                bool ans = iscycle(i,visited,adj);
                if(ans == 1)
                    return true;
            }
        }
        return false;
    }
};

//using dfs
class Solution {
  public:
    bool iscycle(int node,int parent,unordered_map<int,bool> &visited,vector<int> adj[]){
       visited[node]=true;
       for(auto i:adj[node]){
           if(!visited[i]){
               bool cycledetected=iscycle(i,node,visited,adj);
               if(cycledetected)
                    return true;
           }
           else if(i != parent)
                return true;
       }
       return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        unordered_map<int,bool> visited;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                bool ans = iscycle(i,-1,visited,adj);
                if(ans == 1)
                    return true;
            }
        }
        return false;
    }
};
