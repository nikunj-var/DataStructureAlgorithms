class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int c=0; //count of fresh oranges
        int ans=0;
        
        queue<pair<int,int>> q; //for storing the indices of rotten oranges
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                 if(grid[i][j] == 1)
                    c++;
            }
         }
        
        while(!q.empty()){
            int size=q.size();
            
            if(c==0)
                return ans; 
            
            while(size--){
                auto temp=q.front();
                q.pop();
                
                int i=temp.first;
                int j=temp.second;
                
                if(i > 0){
                    if(grid[i-1][j] == 1){
                        c--;
                        grid[i-1][j]=2;
                        q.push({i-1,j});
                    }
                }
                if(j > 0){
                    if(grid[i][j-1] == 1){
                        c--;
                        grid[i][j-1]=2;
                        q.push({i,j-1});
                    }
                }
                if(i < m-1){
                    if(grid[i+1][j] == 1){
                        c--;
                        grid[i+1][j]=2;
                        q.push({i+1,j});
                    }
                }
                if(j < n-1){
                    if(grid[i][j+1] == 1){
                        c--;
                        grid[i][j+1]=2;
                        q.push({i,j+1});
                    }
                }
            }
            ans++;
        }
        
        return c==0 ? ans : -1;
    }
};