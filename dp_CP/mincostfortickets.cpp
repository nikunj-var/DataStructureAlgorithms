//using recursion
class Solution {
public:
    int solve(int n,vector<int>& days, vector<int>& costs,int index){
        if(index >= n){
            return 0;
        }
        //day1
        int option1=costs[0]+solve(n,days,costs,index+1);

        int i;
        //day 7
        for(i=index;i<n && days[i] < days[index]+7;i++);
        int option2=costs[1]+solve(n,days,costs,i);

        //day30
         for(i=index;i<n && days[i] < days[index]+30;i++);
        int option3=costs[2]+solve(n,days,costs,i);

        return min(option1,min(option2,option3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return solve(days.size(),days,costs,0);
    }
};

//using top-down approach
class Solution {
public:
    int solve(int n,vector<int>& days, vector<int>& costs,int index,vector<int>& dp){
        if(index >= n){
            return 0;
        }

        if(dp[index] != -1)
            return dp[index];
        //day1
        int option1=costs[0]+solve(n,days,costs,index+1,dp);

        int i;
        //day 7
        for(i=index;i<n && days[i] < days[index]+7;i++);
        int option2=costs[1]+solve(n,days,costs,i,dp);

        //day30
        for(i=index;i<n && days[i] < days[index]+30;i++);
        int option3=costs[2]+solve(n,days,costs,i,dp);

        dp[index]= min(option1,min(option2,option3));
        return dp[index];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,-1);
        return solve(days.size(),days,costs,0,dp);
    }
};

//using tabulation
class Solution {
public:
    int solve(int n,vector<int>& days, vector<int>& costs){
        vector<int> dp(n+1,INT_MAX);
       dp[n]=0;
        for(int index=n-1;index>=0;index--){
            //day1
            int option1=costs[0] + dp[index+1];

            int i;
            //day 7
            for(i=index;i<n && days[i] < days[index]+7;i++);
                int option2=costs[1]+dp[i];
            //day30
            for(i=index;i<n && days[i] < days[index]+30;i++);
                int option3=costs[2]+dp[i];

            dp[index]= min(option1,min(option2,option3));
        }
       
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        return solve(days.size(),days,costs);
    }
};

//space optimisation
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans=0;
        queue<pair<int,int>> monthly;
        queue<pair<int,int>> weekly;

        for(auto day:days){
            while(!monthly.empty() && monthly.front.first + 30  <= day){
                monthly.pop();
            }
            while(!weekly.empty() && weekly.front.first + 7 <= day){
                weekly.pop();
            }
            weekly.push(make_pair(day,ans+cost[1]));
            monthly.push(make_pair(day,ans+cost[2]));
            ans=min(ans+cost[0],min(monthly.front.first,weekly.front.first));
        }
        return ans;
    }
};