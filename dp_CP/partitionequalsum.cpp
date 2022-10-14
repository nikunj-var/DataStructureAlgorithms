//using recursion
class Solution {
public:
    int solve(int index,vector<int>& nums,int n,int target){
        if(index >= n || target < 0)
            return 0;
        if(target == 0)
            return 1;
        int incl=solve(index+1,nums,n,target-nums[index]);
        int excl=solve(index+1,nums,n,target);
        return incl or excl;        
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total & 1)
            return false;
        int target=total/2;
        return solve(0,nums,nums.size(),target);
    }
};

//using recursion and memoization
class Solution {
public:
    int solve(int index,vector<int>& nums,int n,int target,vector<vector<int>>& dp){
        if(index >= n || target < 0)
            return 0;
        if(target == 0)
            return 1;
            if(dp[index][target] != -1)
                return dp[index][target];
        int incl=solve(index+1,nums,n,target-nums[index],dp);
        int excl=solve(index+1,nums,n,target,dp);
        return dp[index][target]=incl or excl;        
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total & 1)
            return false;
        int target=total/2;
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,-1));
        return solve(0,nums,nums.size(),target,dp);
    }
};

//using tabulation
class Solution {
public:
    int solve(int index,vector<int>& nums,int n,int total){
        
        vector<vector<int>> dp(n+1,vector<int> (total+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }      

        for(int index=n-1;index >=0;index--){
            for(int target=0;target<=total/2;target++){
                bool incl=0;
                if(target-nums[index] >= 0)
                    incl=dp[index+1][target-nums[index]];
                bool excl=dp[index+1][target];

                dp[index][target]=incl or excl;   
            }
        }
        return dp[0][total/2];
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total & 1)
            return false;
        int target=total/2;
       
        return solve(0,nums,nums.size(),total);
    }
};
//using space optimisation
class Solution {
public:
    int solve(int index,vector<int>& nums,int n,int total){
        vector<int> curr(total+1,0);
        vector<int> next(total+1,0);

        curr[0]=1;
        next[0]=1;
       
       for(int index=n-1;index>=0;index--){
          for(int target=0;target<=total/2;target++){
                bool incl=0;
                if(target-nums[index] >= 0)
                    incl=next[target-nums[index]];
                bool excl=next[target];

                curr[target]=incl or excl;   
            }
            next=curr;
        }
        return curr[total/2];
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total & 1)
            return false;
        int target=total/2;
       
        return solve(0,nums,nums.size(),total);
    }
};