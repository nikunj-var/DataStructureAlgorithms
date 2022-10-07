//using recursion

class Solution {
public:
    int solve(vector<int>& satisfaction,int index,int time){
        if(index == satisfaction.size())
            return 0;

        int include=satisfaction[index] * (time+1) + solve(satisfaction,index+1,time+1);
        int exclude=0+solve(satisfaction,index+1,time);

        return max(include,exclude);    
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction,0,0);
    }
};

//using top-down approach
class Solution {
public:
    int solve(vector<int>& satisfaction,int index,int time,vector<vector<int>>& dp){
        if(index == satisfaction.size())
            return 0;

        if(dp[index][time] != -1)
            return dp[index][time];    
        int include=satisfaction[index] * (time+1) + solve(satisfaction,index+1,time+1,dp);
        int exclude=0+solve(satisfaction,index+1,time,dp);

        return dp[index][time] = max(include,exclude);    
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,-1));
        return solve(satisfaction,0,0,dp);
    }
};

//using bottom-up
class Solution {
public:
    int solve(vector<int>& satisfaction){
        vector<vector<int>> dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,0));
        for(int index=satisfaction.size()-1 ; index>=0 ;index--){
            for(int time=index;time>=0;time--){
                int include=satisfaction[index] * (time+1) + dp[index+1][time+1];
                int exclude=0 + dp[index+1][time];

                dp[index][time]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
       
        return solve(satisfaction);
    }
};

//using space optimisation
class Solution {
public:
    int solve(vector<int>& satisfaction){
        vector<int> curr(satisfaction.size()+1, 0);
        vector<int> next(satisfaction.size()+1, 0);
        
        for(int index=satisfaction.size()-1 ; index>=0 ;index--){
            for(int time=index;time>=0;time--){
                int include=satisfaction[index] * (time+1) + next[time+1];
                int exclude=0 + next[time];

                curr[time]=max(include,exclude);
            }
            next=curr;
        }
        return next[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
       
        return solve(satisfaction);
    }
};