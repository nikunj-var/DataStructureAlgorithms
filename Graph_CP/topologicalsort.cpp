#include<bits/stdc++.h>
using namespace std;
//using dfs
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void toposort(auto node,vector<bool>& vis, stack<int>& s,vector<int> adj[]){
	    vis[node]=1;
	    for(auto i:adj[node]){
	        if(!vis[i]){
	            toposort(i,vis,s,adj);
	        }
	    }
	    	        s.push(node);
	}
	vector<int> topoSort(int v, vector<int> adj[]) 
	{   vector<int> ans;
	    vector<bool> vis(v);
	    stack<int> s;
	    for(int i=0;i<v;i++){
	        if(!vis[i]){
	            toposort(i,vis,s,adj);
	        }
	    }
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};

//using bfs || KAHN'S ALGORITHM
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	   vector<int> indegree(v,0);
	   //int s=adj.size();
	   for(int i=0;i<v;i++){
	       for(auto j:adj[i]){
	           indegree[j]++;
	       }
	   }
	   
	   queue<int> q;
	   for(int i=0;i<v;i++){
	       if(indegree[i] == 0)
	        q.push(i);
	   }
	   vector<int> ans;
	   while(!q.empty()){
	       int front=q.front();
	       q.pop();
	       ans.push_back(front);
	       for(auto i:adj[front]){
	           indegree[i]--;
	           if(indegree[i] == 0)
	            q.push(i);
	       }
	   }
	   return ans;
	}
};