// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where
//  connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other
//   computer directly or indirectly through the network.

// // You are given an initial computer network connections. You can extract certain cables between two directly 
// connected computers, and place them between any pair of disconnected computers to make them directly connected.

// // Return the minimum number of times you need to do this in order to make all the computers connected. If it is 
// not possible, return -1.


class Solution {
public:
    void dfs(int node, vector<bool>& visited,vector<int> adj[]){
        visited[node]=true;
        
        for(auto nbr : adj[node]){
            if(!visited[nbr])
                dfs(nbr,visited,adj);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int ans=0;
        vector<int> adj[n];
        vector<bool> visited(n,0);

        //if no of connections is less than n-1 then return -1 because n-1 connections is the min no of edges to connect all nodes of graph with n vertices
        if(connections.size() < n-1){
            return -1;
        }
        
        //create adjacency list
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
             adj[i[1]].push_back(i[0]);
        }
        
        //do dfs 
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(i,visited,adj);
            }
        }
        
        return ans-1;
    }
};