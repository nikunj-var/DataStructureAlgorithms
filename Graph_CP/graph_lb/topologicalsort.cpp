class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void dfs(int i,stack<int>& s,unordered_map<int,bool>& mp,vector<int> adj[]){
	    mp[i]=true;
	    for(auto node:adj[i]){
	        if(!mp[node])
	            dfs(node,s,mp,adj);
	    }
	    s.push(i);
	}
	vector<int> topoSort(int v, vector<int> adj[]) 
	{  unordered_map<int,bool> mp;
	   stack<int> s;
	   for(int i=0;i<v;i++){
	       if(!mp[i])
	        dfs(i,s,mp,adj);
	   }
	   vector<int> ans;
	   while(!s.empty()){
	       ans.push_back(s.top());
	       s.pop();
	   }
	   return ans;
	}
};