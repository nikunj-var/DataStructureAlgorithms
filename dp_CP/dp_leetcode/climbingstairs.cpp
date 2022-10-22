//using recursion
class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n == 0)
            return 1;
        if(n < 0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        return dp[n]=solve(n-1,dp)+solve(n-2,dp); 
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};

//using recursion and memoization
class Solution {
public:
    int solve(int n){
        vector<int> dp(n+1);
        if(n == 0 || n == 1)
            return 1;
            
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
       
        return solve(n);
    }
};

//using tabulation
class Solution {
public:
    int solve(int n){
        if(n == 0 || n==1)
            return 1;
        int prev0=1;
        int prev1=1;
        int curr=0;
        for(int i=2;i<=n;i++){
            curr=prev0+prev1;
            prev0=prev1;
            prev1=curr;
        }
        return curr;
    }
    int climbStairs(int n) {
       
        return solve(n);
    }
};