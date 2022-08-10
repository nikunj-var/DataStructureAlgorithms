#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class graph{
    public:
    int v;
    graph(int v){
        this->v=v;
    }
    //adjacency function
    void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
    }
    void dfs(vector<int> adj[],int n,vector<bool>& visited){
        visited[n]=true;
        cout<<n<<" ";
        for(auto i:adj[n]){
            if(!visited[i]){
                dfs(adj,i,visited);
            }
        }
    } 

    void printgraph(vector<int> adj[],int v){
    for(int i=0;i<v;i++){
        cout<<i;
        for(auto j:adj[i]){
           cout<<"->"<<j;
            }
        cout<<endl;
        }
    }

};


int main(){
    
    vector<int> adj[4];
    vector<bool> visited(4,false);
    graph *g=new graph(4);
    g->addedge(adj, 0, 1);
    g->addedge(adj, 0, 2);
    g->addedge(adj, 1, 2);
    g->addedge(adj, 2, 0);
    g->addedge(adj, 2, 3);
    //g->addedge(adj, 2, 3);
    g->addedge(adj, 3, 3);
    //g->printgraph(adj,5);
    g->dfs(adj,2,visited);
}