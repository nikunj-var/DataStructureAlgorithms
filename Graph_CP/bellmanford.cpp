class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n+1,INT_MAX);
	    
	    int m=edges.size();
	    
	    dist[0]=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            int u=edges[j][0];
	            int v=edges[j][1];
	            int w=edges[j][2];
	            
	            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
	                dist[v]=dist[u]+w;
	            }
	        }
	    }
	    
	    //check for cycle
	    for(int j=0;j<m;j++){
	            bool flag=0;
	            int u=edges[j][0];
	            int v=edges[j][1];
	            int w=edges[j][2];
	            
	            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
	                flag=1;
	            }
	       if(flag)
	            return 1;
	    }
	    return 0;
	}
};