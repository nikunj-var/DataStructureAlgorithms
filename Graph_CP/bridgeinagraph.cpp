#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int parent,int &timer,vector<int>& disc,vector<int>& low,vector<vector<int>>& res,unordered_map<int,list<int>> adj[],unordered_map<int,bool>& visited){
    visited[node]=true;
    disc[node]=low[node]=timer++;

    for(auto nbr: adj[node]){
        if(nbr == parent)
            continue;
        if(!visited[nbr]){
            dfs(nbr,node,timer,disc,low,res,adj,visited);

            low[node]=min(low[node],low[nbr]);

            //check edge is bridge or  not
            if(low[nbr] > disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                res.push_back(ans);
            }
            else{
                //back edge
                low[node]=min(low[node],disc[nbr]);
            }
        }    
    }
}
vector<vector<int>> findbridge(vector<vector<int>> edges,int v,int e){
    unordered_map<int,list<int>> adj;
    //timer to store the time at which we reach the node
    int timer=0;
    //disc is to store at which time our pointer points that node
    vector<int> disc(v,-1);
    //low tells the minimum distance to reach that node from other node
    vector<int> low(v,-1);
    int parent=-1;
    unordered_map<int,bool> visited;
    vector<vector<int>> res;

    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,parent,timer,disc,low,res,adj,visited);
        }
    }

}