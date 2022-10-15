//using topological sort
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& p) {
	    vector<int > adj[n];
	   vector<int> indegree(n,0);
	  
	    for(int i=0;i<p.size();i++){
	        adj[p[i].second].push_back(p[i].first);
	        indegree[p[i].first]++;
	    }
	    int c=0;
	    queue<int> q;
	    for(int i=0;i<n;i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    while(!q.empty()){
	        auto curr=q.front();
	        q.pop();
	        c++;
	        for(auto i:adj[curr]){
	            indegree[i]--;
	            if(indegree[i] == 0)
	                q.push(i);
	        }
	    }
	    return (c!=n) ? false:true;
	}
};
