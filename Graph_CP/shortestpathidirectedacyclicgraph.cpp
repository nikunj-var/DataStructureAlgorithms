// We initialize distances to all vertices as infinite and distance to source as 0, then we find a topological sorting
//   of the graph. Topological Sorting of a graph represents a linear ordering of the graph (See below, figure (b) is a
//   linear representation of figure (a) ). Once we have topological order (or linear representation), we one by one process
//   all vertices in topological order. For every vertex being processed, we update distances of its adjacent using distance
//    of current vertex.
#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addedge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }
    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo)
    {
        visited[node] = true;
        for (auto i : adj[node])
        {
            if (!visited[i.first])
            {
                dfs(i.first, visited, topo);
            }
        }
        topo.push(node);
    }
    void getshortestpath(int source, vector<int> &dist, stack<int> &topo)
    {
        dist[source] = 0;
        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();
            if (dist[top] != INT_MAX)
            {
                for (auto i : adj[top])
                {
                    if (dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};
int main()
{
    int n = 6;
    graph g;
    g.addedge(0, 1, 5);
    g.addedge(0, 2, 3);
    g.addedge(1, 2, 2);
    g.addedge(1, 3, 6);
    g.addedge(2, 3, 7);
    g.addedge(2, 4, 4);
    g.addedge(2, 5, 2);
    g.addedge(3, 4, -1);
    g.addedge(4, 5, -2);

    unordered_map<int, bool> visited;
    stack<int> topo;
    vector<int> dist(n, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, topo);
        }
    }
    int source = 0;
    g.getshortestpath(source, dist, topo);
    cout << "the shortest distance are\n";
    for (int i = 0; i < n; i++)
    {
        cout << 0 << "->" << i << " = " << dist[i] << endl;
    }
}