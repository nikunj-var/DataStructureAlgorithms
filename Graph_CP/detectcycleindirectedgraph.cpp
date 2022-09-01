//For a disconnected graph, Get the DFS forest as output. To detect cycle, check for a cycle in individual trees by
// checking back edges.
// To detect a back edge, keep track of vertices currently in the recursion stack of function for DFS traversal. If
// a vertex is reached that is already in the recursion stack, then there is a cycle in the tree. The edge 
// connects the current vertex to the vertex in the recursion stack is a back edge. Use recStack[] array to keep 
//track of vertices in the recursion stack.

//using dfs
class Solution {
  public:
  bool checkcycle(int src,vector<int>&vis,vector<int>&dfsvis,vector<int> adj[]){
      
        vis[src]=true;
        dfsvis[src]=1;
        
        for(auto i:adj[src]){
            if(!vis[i]){
                bool cycledetect=checkcycle(i,vis,dfsvis,adj);
                if(cycledetect)
                    return true;
            }
            else if(dfsvis[i])
                return true;
        }
        dfsvis[src]=0;
        return false;
      
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       vector<int> vis(V,0);
       vector<int> dfsvis(V,0);
       for(int i=0;i<V;i++){
           if(!vis[i]){
               bool c=checkcycle(i,vis,dfsvis,adj);
               if(c)
               return true;
           }
       }
       return false;
    }
};