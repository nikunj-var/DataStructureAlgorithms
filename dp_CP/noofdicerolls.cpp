
class Solution {
public:
    int solve(int dice,int faces,int target){
        if(target < 0)
            return 0;
        if(target == 0 && dice == 0)
            return 1;
        if(dice == 0 && target != 0)
            return 0;
        if(dice != 0 && target == 0)
            return 0;
        int ans=0;
        for(int i=1;i<=faces;i++){
            ans=ans+solve(dice-1,faces,target-i);
        }            
        return ans%1000000007;
    }
    int numRollsToTarget(int n, int k, int target) {
        return solve(n,k,target);
    }
};

//using recursion and memoization
class Solution {
public:
    int solve(int dice,int faces,int target, vector<vector<int>>& dp){
        if(target < 0)
            return 0;
        if(target == 0 && dice == 0)
            return 1;
        if(dice == 0 && target != 0)
            return 0;
        if(dice != 0 && target == 0)
            return 0;
        if(dp[dice][target] != -1)
            return dp[dice][target]; 
        int ans=0;
        for(int i=1;i<=faces;i++){
            ans=(ans+solve(dice-1,faces,target-i,dp))%1000000007;
        }    
        dp[dice][target] =  ans%1000000007;     
        return ans%1000000007;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};

//using tabulation

class Solution {
public:
    int solve(int d,int f,int t){
        vector<vector<int>> dp(d+1,vector<int>(t+1,0));
        dp[0][0]=1;

        for(int dice=1;dice<=d;dice++){
            for(int target=1;target<=t;target++){
                int ans=0;
                for(int i=1;i<=f;i++){
                    if(target-i >= 0)    
                        ans=(ans+dp[dice-1][target-i])%1000000007;
                }
                dp[dice][target]=ans;
            }
        }
        return dp[d][t]; 
    }
    int numRollsToTarget(int n, int k, int target) {
        return solve(n,k,target);
    }
};

//using space optimisation
class Solution {
public:
    int solve(int d,int f,int t){
      
        vector<int> prev(t+1,0);
        vector<int> curr(t+1,0);
        prev[0]=1;

        for(int dice=1;dice<=d;dice++){
            for(int target=1;target<=t;target++){
                int ans=0;
                for(int i=1;i<=f;i++){
                    if(target-i >= 0)    
                        ans=(ans+prev[target-i])%1000000007;
                }
                curr[target]=ans;
            }
            prev=curr;
        }
        return prev[t]; 
    }
    int numRollsToTarget(int n, int k, int target) {
        return solve(n,k,target);
    }
};