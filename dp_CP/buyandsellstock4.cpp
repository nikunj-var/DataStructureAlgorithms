//using recursion
class Solution {
public:
    int solve(int index,int operationno,int k, vector<int>& prices){
        if(index == prices.size() || operationno == 2*k)
            return 0;
        
        int profit=0; 
        
        if(operationno %2 == 0)
        {
            //buy karo
            int buykaro=-prices[index] + solve(index+1,operationno+1,k,prices);
            int skipkaro=0 + solve(index+1,operationno,k,prices);
            profit = max(buykaro,skipkaro);
        }           
        else{
            int sellkaro = +prices[index] + solve(index+1,operationno+1,k,prices);
            int skipkaro=0 + solve(index+1,operationno,k,prices);
             profit = max(sellkaro,skipkaro);
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        return solve(0,0,k,prices);
    }
};

//using recursion and memoization
class Solution {
public:
    int solve(int index,int operationno,int k, vector<int>& prices, vector<vector<int>>& dp){
        if(index == prices.size() || operationno == 2*k)
            return 0;
        
        if(dp[index][operationno] != -1)
            return dp[index][operationno];

        int profit=0; 

        if(operationno %2 == 0)
        {
            //buy karo
            int buykaro=-prices[index] + solve(index+1,operationno+1,k,prices,dp);
            int skipkaro=0 + solve(index+1,operationno,k,prices,dp);
            profit = max(buykaro,skipkaro);
        }           
        else{
            int sellkaro = +prices[index] + solve(index+1,operationno+1,k,prices,dp);
            int skipkaro=0 + solve(index+1,operationno,k,prices,dp);
             profit = max(sellkaro,skipkaro);
        }
        return dp[index][operationno]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2*k,-1));
        return solve(0,0,k,prices,dp);
    }
};

//using tabulation
class Solution {
public:

    int solve(int k, vector<int>& prices){
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
        
        for(int index=n-1;index>=0;index--){
            for(int operation=0;operation<2*k;operation++){
                int profit=0;
                if(operation%2==0){
                    int buykaro=-prices[index] + dp[index+1][operation+1];
                    int skipkaro=0 + dp[index+1][operation];
                    profit = max(buykaro,skipkaro);
                }
                else{
                    int sellkaro = +prices[index] + dp[index+1][operation+1];
                    int skipkaro=0 + dp[index+1][operation];
                    profit = max(sellkaro,skipkaro);
                 }
                dp[index][operation]=profit;
            }
        }
        return dp[0][0];
    }
    int maxProfit(int k, vector<int>& prices) {
       return solve(k,prices);
    }
};

//using space optimisation
class Solution {
public:

    int solve(int k, vector<int>& prices){
        int n=prices.size();
        vector<int> curr(2*k+1,0);
        vector<int> next(2*k+1,0);
        for(int index=n-1;index>=0;index--){
            for(int operation=0;operation<2*k;operation++){
                int profit=0;
                if(operation%2==0){
                    int buykaro=-prices[index] + next[operation+1];
                    int skipkaro=0 + next[operation];
                    profit = max(buykaro,skipkaro);
                }
                else{
                    int sellkaro = +prices[index] + next[operation+1];
                    int skipkaro=0 + next[operation];
                    profit = max(sellkaro,skipkaro);
                 }
               curr[operation]=profit;
            }
            next=curr;
        }
        return next[0];
    }
    int maxProfit(int k, vector<int>& prices) {
       return solve(k,prices);
    }
};