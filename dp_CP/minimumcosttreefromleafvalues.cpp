//using recursion
class Solution {
public:
    int solve(vector<int>& arr,map<pair<int,int>,int>& m,int left,int right){
        if(left == right)   
            return 0;
        int ans=INT_MAX;
        for(int i=left;i<right;i++){
            ans=min(ans,m[{left,i}]*m[{i+1,right}]+solve(arr,m,left,i)+solve(arr,m,i+1,right));
        }    
        return ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> m;
        for(int i=0;i<arr.size();i++){
            m[{i,i}]=arr[i];
            for(int j=i+1;j<arr.size();j++){
                m[{i,j}]=max(arr[j],m[{i,j-1}]);
            }
        }
        return solve(arr,m,0,arr.size()-1);
    }
};

//using recursion and memoization
class Solution {
public:
    int solve(vector<int>& arr,map<pair<int,int>,int>& m,int left,int right,vector<vector<int>>& dp){
        if(left == right)   
            return 0;
        if(dp[left][right] != -1)
            return dp[left][right];
        int ans=INT_MAX;
        for(int i=left;i<right;i++){
            ans=min(ans,m[{left,i}]*m[{i+1,right}]+solve(arr,m,left,i,dp)+solve(arr,m,i+1,right,dp));
        }    
        return dp[left][right]=ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> m;
        for(int i=0;i<arr.size();i++){
            m[{i,i}]=arr[i];
            for(int j=i+1;j<arr.size();j++){
                m[{i,j}]=max(arr[j],m[{i,j-1}]);
            }
        }
        vector<vector<int>> dp(arr.size(),vector<int> (arr.size(),-1));
        return solve(arr,m,0,arr.size()-1,dp);
    }
};