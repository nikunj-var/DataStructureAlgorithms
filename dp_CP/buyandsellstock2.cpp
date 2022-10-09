//using recursion

class Solution {
public:
    int solve(int index,int buy,vector<int>& prices){
        if(index == prices.size())
            return 0;

        int profit=0;
        if(buy){
            int buykaro=-prices[index] + solve(index+1,0,prices);
            int skipkaro=0 + solve(index+1,1,prices);
            profit = max(buykaro,skipkaro);
        }           
        else{
            int sellkaro = +prices[index] + solve(index+1, 1,prices);
            int skipkaro=0 + solve(index+1,0,prices);
             profit = max(sellkaro,skipkaro);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(0,1,prices);
    }
};

//using recursion and memoization
class Solution {
public:
    int solve(int index,int buy,vector<int>& prices,vector<vector<int>>& dp){
        if(index == prices.size())
            return 0;

        if(dp[index][buy] != -1)
            return dp[index][buy];

        int profit=0;
        if(buy){
            int buykaro=-prices[index] + solve(index+1,0,prices,dp);
            int skipkaro=0 + solve(index+1,1,prices,dp);
            profit = max(buykaro,skipkaro);
        }           
        else{
            int sellkaro = +prices[index] + solve(index+1, 1,prices,dp);
            int skipkaro=0 + solve(index+1,0,prices,dp);
             profit = max(sellkaro,skipkaro);
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};

//using tabulation
class Solution {
public:
    int solve(vector<int>& prices){
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));

        for(int index = prices.size()-1 ; index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                    if(buy){
                        int buykaro=-prices[index] + dp[index+1][0];
                        int skipkaro=0 + dp[index+1][1];
                        profit = max(buykaro,skipkaro);
                    }           
                    else{
                        int sellkaro = +prices[index] +dp[index+1][1];
                        int skipkaro=0 + dp[index+1][0];
                        profit = max(sellkaro,skipkaro);
                    }
                dp[index][buy]=profit;    
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};

//using space optimisation
class Solution {
public:
    int solve(vector<int>& prices){
        vector<int> nextrow(2,0);
        vector<int> currrow(2,0);
        for(int index = prices.size()-1 ; index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                    if(buy){
                        int buykaro=-prices[index] + nextrow[0];
                        int skipkaro=0 + nextrow[1];
                        profit = max(buykaro,skipkaro);
                    }           
                    else{
                        int sellkaro = +prices[index] + nextrow[1];
                        int skipkaro=0 + nextrow[0];
                        profit = max(sellkaro,skipkaro);
                    }
                currrow[buy]=profit;    
            }
            nextrow=currrow;
        }
        return nextrow[1];
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};