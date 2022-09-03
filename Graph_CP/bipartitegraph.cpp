#include<bits/stdc++.h>
using namespace std;

//using bfs
class Solution {
public:
    bool bipartite(int node,int color[],vector<int> adj[]) {
        color[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto i:adj[front]){
                if(color[i] == -1)
                {
                    color[i]=1-color[front];
                    q.push(i);
                }
                else if(color[i] == color[front])
                    return false;
            }
        }
        return true;
        
    }
	bool isBipartite(int v, vector<int>adj[]){
	    int color[v];
	    for(int i=0;i<v;i++){
	        color[i]=-1;
	    }
	    for(int i=0;i<v;i++){
	        if(color[i] == -1){
	            if(!bipartite(i,color,adj))
	                return false;
	        }
	    }
	    return true;
	}

};

//using dfs
class Solution {
public:
    bool bipartite(int node,int color[],vector<int> adj[]) {
        if(color[node] == -1)
            color[node]=1;
       
            for(auto i:adj[node]){
                if(color[i] == -1)
                {
                    color[i]=1-color[node];
                    if(!bipartite(i,color,adj))
                        return false;
                }
                else if(color[i] == color[node])
                    return false;
            }
        return true;
    }
	bool isBipartite(int v, vector<int>adj[]){
	    int color[v];
	    for(int i=0;i<v;i++){
	        color[i]=-1;
	    }
	    for(int i=0;i<v;i++){
	        if(color[i] == -1){
	            if(!bipartite(i,color,adj))
	                return false;
	        }
	    }
	    return true;
	}

};
