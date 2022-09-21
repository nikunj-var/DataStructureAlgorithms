//top-down approach
class Solution {
public:
    int solve(vector<int>& cost,int n,vector<int>& dp){
        if(n == 0 || n == 1)
            return cost[n];
        
        if(dp[n] != -1){
            return dp[n]; 
        }
        
        dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return ans;    
    }
};

//bottom-up approach
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};

//space optimisation
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1=cost[0];
        int prev2=cost[1];
        
        for(int i=2;i<cost.size();i++){
            int curr=cost[i]+min(prev1,prev2);
            prev1=prev2;
            prev2=curr;
        }
        return min(prev1,prev2);
    }
};