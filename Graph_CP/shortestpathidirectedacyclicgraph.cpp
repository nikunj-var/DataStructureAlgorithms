//We initialize distances to all vertices as infinite and distance to source as 0, then we find a topological sorting
//  of the graph. Topological Sorting of a graph represents a linear ordering of the graph (See below, figure (b) is a 
//  linear representation of figure (a) ). Once we have topological order (or linear representation), we one by one process 
//  all vertices in topological order. For every vertex being processed, we update distances of its adjacent using distance
//   of current vertex.

#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<pair<int,int>>> adj;
void dfs(int node,unordered_map<int,bool> &vis,stack<int> &s){
    vis[node]=true;

    for(auto i:adj[node]){
        if(!vis[i.first]){
            dfs(i.first ,vis,s);
        }
    }
    s.push(node);
}

void getshortestpath(int src,vector<int>& dist,stack<int> & topo){
    dist[src]=0;

    while(!topo.empty()){
        int top=topo.top();
        topo.pop();
        if(dist[top] != INT_MAX){
            for(auto i:adj[top]){
                if(dist[top] + i.second < dist[i.first]){
                    dist[i.first] = dist[top]+i.second;
                }
            }
        }
    }
}

//first call toposort after that call getshortestpath