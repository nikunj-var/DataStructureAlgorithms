
#include <bits/stdc++.h>
using namespace std;
class Graph {
   
    int V;
 
public:
     vector<vector<int> > edgelist;

    Graph(int V) { this->V = V; }
 
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({ w, x, y });
    }
};

void makeset(vector<int>& parent,vector<int>& rank,int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=1;
    }
}

int findparent(vector<int>& p,int i){
    if(p[i] == i){
        return i;
    }
    return findparent(p,p[i]);
}

void unionset(int u,int v,vector<int>& p,vector<int>& r){
    int s1=findparent(p,u);
    int s2=findparent(p,v);
    if(s1 != s2){
        if(r[s1] < r[s2]){
            p[s1]=s2;
            r[s2]+=r[s1];
        }
        else{
            p[s2]=s1;
            r[s1]+=r[s2];
        }
    }
}
int kruskal(vector<vector<int>> g){
    sort(g.begin(),g.end());

    vector<int> parent(6);
    vector<int> rank(6);

    makeset(parent,rank,6);

    int minweight=0;

    for(int i=0;i<g.size();i++){
        int u=findparent(parent,g[i][1]);
        int v=findparent(parent,g[i][2]);

        if(u != v){
            minweight+=g[i][0];
            unionset(u,v,parent,rank);
        }
    }
}
 
// Driver's code
int main()
{
    /* Let us create following weighted graph
                   10
              0--------1
              |  \     |
             6|   5\   |15
              |      \ |
              2--------3
                  4       */
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
 
      // Function call
    cout<<kruskal(g.edgelist);
    return 0;
}


int minimumspanning(vector<vector<int>>&edges,int n){
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent()
}