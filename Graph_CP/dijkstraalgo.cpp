#include<bits/stdc++.h>
`using namespace std;

unordered_map<int,list<pair<int,int>>> adj;
vector<int> dijkstra(vector<vector<int>>& vec,int v,int e,int source){
    vector<int> dist(v,INT_MAX);

    set<pair<int,int>> s;

    dist[source]=0;
    s.insert(make_pair(0,source));

    while(!s.empty()){

        auto top=*(s.begin());

        int nodedistance=top.first;
        int topnode=top.second;
        s.erase(s.begin());

        for(auto i:adj[topnode]){
            if(nodedistance + i.second < dist[i.first]){
                auto record=s.find(make_pair(dist[i.first],i.first));

                if(record != s.end())
                    s.erase(record);

                dist[i.first]=nodedistance + i.second;

                s.insert(make_pair(dist[i.first],i.first));    
            }
        }
    }
    return dist;
}