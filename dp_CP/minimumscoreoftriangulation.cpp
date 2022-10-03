//using recursion
class Solution {
public:
    int solve(vector<int>& v,int i,int j){
        if(i+1 == j)
            return 0;

        int ans=INT_MAX;
        for(int k=i+1 ;k<j;k++){
            ans=min(ans,v[i]*v[j]*v[k] + solve(v,i,k) + solve(v,k,j));
        } 
        return ans;   
    }
    int minScoreTriangulation(vector<int>& values) {
        return solve(values,0,values.size()-1);
    }
};

//using recursion and memoization
class Solution {
public:
    int solve(vector<int>& v,int i,int j, vector<vector<int>>& dp){
        if(i+1 == j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int ans=INT_MAX;
        for(int k=i+1 ;k<j;k++){
            ans=min(ans,v[i]*v[j]*v[k] + solve(v,i,k,dp) + solve(v,k,j,dp));
        } 
        dp[i][j]=ans;
        return ans;   
    }
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(values.size(),vector<int>(values.size(),-1));
        return solve(values,0,values.size()-1,dp);
    }
};

//using tabulation
class Solution {
public:
    int solve(vector<int>& v){
        vector<vector<int>> dp(v.size(),vector<int>(v.size(),0));

        int n=v.size();

        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n;j++){
                    int ans=INT_MAX;
                    for(int k=i+1 ;k<j;k++){
                        ans=min(ans,v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
                    }
                dp[i][j]=ans;     
            }
        }

        return dp[0][n-1];
    }
    int minScoreTriangulation(vector<int>& values) {  
        return solve(values);
    }
};