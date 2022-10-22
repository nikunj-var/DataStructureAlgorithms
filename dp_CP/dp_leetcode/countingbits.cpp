//using recursion
class Solution {
public:
    int solve(int n){
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n % 2 == 0)
            return solve(n/2);
        return 1+solve(n/2);            
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(solve(i));
        }
        return ans;
    }   
};

//using recursion and memoization
class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        if(n % 2 == 0)
            return dp[n]=solve(n/2,dp);
        return dp[n]=1+solve(n/2,dp);            
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        vector<int> dp(n+1,-1);
        for(int i=0;i<=n;i++){
            ans.push_back(solve(i,dp));
        }
        return ans;
    }   
};

//using tabulation
class Solution {
public:
    
    vector<int> countBits(int n) {

        vector<int> ans(n+1);
        
        ans[0]=0;
        if(n == 0)
            return ans;
        ans[1]=1;
        if(n==1)
            return ans;
        for(int i=2;i<=n;i++){
           ans[i]=ans[i/2]+i%2;
        }
        return ans;
    }   
};
