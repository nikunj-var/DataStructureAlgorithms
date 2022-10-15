//use topological sorting

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {   vector<int> ans(n+1,0);
            vector<int> graph[n+1];
            int indegree[n+1];
            int job[n+1];
            for(int i=1;i<=n;i++){
                    indegree[i]=0;
                    job[i]=0;
                    
            }
            
            for(int i=0;i<edges.size();i++){
                graph[edges[i][0]].push_back(edges[i][1]);
                indegree[edges[i][1]]++;
            }
            queue<int> q;
            for(int i=1;i<=n;i++){
                if(indegree[i] == 0){
                    q.push(i);
                    ans[i]=1;
                }
            }
            while(!q.empty()){
                auto curr=q.front();
                q.pop();
                
                for(auto adj:graph[curr]){
                    indegree[adj]--;
                    if(indegree[adj] == 0){
                        q.push(adj);
                        ans[adj]=ans[curr]+1;
                    }
                }
            }
            vector<int> v;
            for(int i=1;i<ans.size();i++)
                v.push_back(ans[i]);
            return v;
        }
};