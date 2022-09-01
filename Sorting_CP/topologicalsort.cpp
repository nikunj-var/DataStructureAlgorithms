#include<bits/stdc++.h>
using namespace std;
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
