
class Solution
{
	public:
	void reverse(int v,vector<int> adj[],vector<int> revadj[],unordered_map<int,bool>& visited){
	    for(int i=0;i<v;i++){
	        visited[i]=false;
	        for(auto nbr:adj[i]){
	            revadj[nbr].push_back(i);
	        }
	    }
	}
	void dfs(int node,unordered_map<int,bool>& visited,stack<int>& s,vector<int> adj[]){
	    
	    visited[node]=true;
	    
	    for(auto nbr:adj[node]){
	        if(!visited[nbr])
	            dfs(nbr,visited,s,adj);
	    }
	    s.push(node);
	}
	void revdfs(int node, unordered_map<int,bool>& visited, vector<int> revadj[]){
	    visited[node]=true;
	    for(auto nbr:revadj[node]){
	        if(!visited[nbr]){
	            revdfs(nbr,visited,revadj);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<int> adj[])
    {
        unordered_map<int,bool> visited;
        stack<int> s;
        
        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfs(i,visited,s,adj);
            }
        }
        vector<int> revadj[v];
        reverse(v,adj,revadj,visited);
        int count=0;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            if(!visited[node]){
                revdfs(node,visited,revadj);
                count++;
            }
        }
        return count;
    }
};