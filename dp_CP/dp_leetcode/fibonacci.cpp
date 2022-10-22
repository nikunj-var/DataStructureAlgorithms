//using recursion
class Solution {
public:

    int solve(int n){
        if(n == 0 || n==1)
            return n;
        return solve(n-1)+solve(n-2);    
    }
    int fib(int n) {
        
        return solve(n);
    }
};

//using recursion and memoization
class Solution {
public:

    int solve(int n,vector<int>& dp){
        if(n == 0 || n==1)
            return n;
        if(dp[n] != -1)
            return dp[n];
        return solve(n-1,dp)+solve(n-2,dp);    
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};

//using tabulation
class Solution {
public:

    int solve(int n){
        vector<int> dp(n+1,0);
         if(n == 0 || n==1)
            return n;
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
       
        return dp[n];
    }
    int fib(int n) {
        
        return solve(n);
    }
};
//using spaceoptimisation
class Solution {
public:

    int fib(int n) {
        if(n == 0 || n==1)
            return n;
        int prev1=0;
        int prev2=1;
        int curr;
        for(int i=2;i<=n;i++){
            curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return curr;
    }
};