#include<iostream>
#include<vector>
using namespace std;

//adjacency function
void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//print graph
void printgraph(vector<int> adj[],int v){
    for(int i=0;i<v;i++){
        cout<<i;
        for(auto j:adj[i]){
           cout<<"->"<<j;
        }
        cout<<endl;
    }
}

int main(){
    int v=5;
    vector<int> adj[v];
    addedge(adj, 0, 1);
    addedge(adj, 0, 4);
    addedge(adj, 1, 2);
    addedge(adj, 1, 3);
    addedge(adj, 1, 4);
    addedge(adj, 2, 3);
    addedge(adj, 3, 4);
    printgraph(adj,v);
}

