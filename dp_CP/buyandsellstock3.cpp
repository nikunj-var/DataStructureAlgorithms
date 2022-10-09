//using recursion
class Solution {
public:
    int solve(int index,int buy,vector<int>& prices,int limit){
        if(index == prices.size() || limit == 0)
            return 0;

        int profit=0;
        if(buy){
            int buykaro=-prices[index] + solve(index+1,0,prices,limit);
            int skipkaro=0 + solve(index+1,1,prices,limit);
            profit = max(buykaro,skipkaro);
        }           
        else{
            int sellkaro = +prices[index] + solve(index+1, 1,prices,limit-1);
            int skipkaro=0 + solve(index+1,0,prices,limit);
             profit = max(sellkaro,skipkaro);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(0,1,prices,2);
    }
};

//using recursion and memoization
class Solution {
public:
    int solve(int index,int buy,vector<int>& prices,int limit,vector<vector<vector<int>>>& dp){
        if(index == prices.size() || limit == 0)
            return 0;

        if(dp[index][buy][limit] != -1)
            return dp[index][buy][limit];

        int profit=0;
        if(buy){
            int buykaro=-prices[index] + solve(index+1,0,prices,limit,dp);
            int skipkaro=0 + solve(index+1,1,prices,limit,dp);
            profit = max(buykaro,skipkaro);
        }           
        else{
            int sellkaro = +prices[index] + solve(index+1, 1,prices,limit-1,dp);
            int skipkaro=0 + solve(index+1,0,prices,limit,dp);
             profit = max(sellkaro,skipkaro);
        }
        return dp[index][buy][limit]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
        return solve(0,1,prices,2,dp);
    }
};
//using bottom-up
class Solution {
public:
    int solve(vector<int>& prices){
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (3,vector<int>(4,0)));
        for(int index = prices.size()-1 ; index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=2;limit++){
                    int profit=0;
                    if(buy){
                        int buykaro=-prices[index] + dp[index+1][0][limit];
                        int skipkaro=0 + dp[index+1][1][limit];
                        profit = max(buykaro,skipkaro);
                    }           
                    else{
                        int sellkaro = +prices[index] +dp[index+1][1][limit-1];
                        int skipkaro=0 + dp[index+1][0][limit];
                        profit = max(sellkaro,skipkaro);
                    }
                dp[index][buy][limit]=profit;    
                }  
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return solve(prices);
    }
};
//using space-optimisation
class Solution {
public:
    int solve(vector<int>& prices){
        int n=prices.size();
        vector<vector<int>> next(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        for(int index = prices.size()-1 ; index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=2;limit++){
                    int profit=0;
                    if(buy){
                        int buykaro=-prices[index] + next[0][limit];
                        int skipkaro=0 + next[1][limit];
                        profit = max(buykaro,skipkaro);
                    }           
                    else{
                        int sellkaro = +prices[index] +next[1][limit-1];
                        int skipkaro=0 + next[0][limit];
                        profit = max(sellkaro,skipkaro);
                    }
                curr[buy][limit]=profit;    
                }  
            }
            next=curr;
        }
        return next[1][2];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return solve(prices);
    }
};