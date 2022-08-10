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
    void bfs(vector<int> adj[],int n){
        int temp;
        vector<bool> visited(v,false);
        queue<int> q;
        visited[n]=true;
        q.push(n);
        while(!q.empty()){
            temp=q.front();
            cout<<temp<<" ";
            q.pop();
            for(auto a:adj[temp]){
                if(!visited[a]){
                    visited[a]=true;
                    q.push(a);
                }
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
    graph *g=new graph(4);
    g->addedge(adj, 0, 1);
    g->addedge(adj, 0, 2);
    g->addedge(adj, 1, 2);
    g->addedge(adj, 2, 0);
    g->addedge(adj, 2, 3);
    //g->addedge(adj, 2, 3);
    g->addedge(adj, 3, 3);
    //g->printgraph(adj,5);
    g->bfs(adj,2);
}


//TIME COMPLEXITY-0(V+E)
//SPACE COMPLEXITY-O(V)
