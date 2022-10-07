//using recursion
class Solution {
public:
    int solve(int n,vector<int>& nums,int curr,int prev){
        //base case
        if(curr == n)
            return 0;

        //apply include - exclude principle
        
        int take=0;
        if(prev == -1 || nums[curr] > nums[prev]){
            take = 1 + solve(n,nums,curr+1,curr);
        }    
        int nottake = 0 + solve(n,nums,curr+1,prev);

        return max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums.size(),nums,0,-1);
    }
};

//using recursion and memoisation
class Solution {
public:
    int solve(int n,vector<int>& nums,int curr,int prev,vector<vector<int>>& dp){
        //base case
        if(curr == n)
            return 0;

        //apply include - exclude principle
        
        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];

        int take=0;
        if(prev == -1 || nums[curr] > nums[prev]){
            take = 1 + solve(n,nums,curr+1,curr,dp);
        }    
        int nottake = 0 + solve(n,nums,curr+1,prev,dp);

        //prev+1 isliye kiya kyuki jab starting me call hoga tb prev=-1 pe index outofbound error ayega 
        //is wajah se prev ko har call me +1 kr diya i.e instead of storing prev indices from -1 to n-1 
        //we use 0 to n that's why in dp array we take n+1 columns 
        return dp[curr][prev+1]= max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1 , -1));
        return solve(nums.size(),nums,0,-1,dp);
    }
};

//using bottom-up
class Solution {
public:
    int solve(int n,vector<int>& nums){
        
        
        //apply include - exclude principle
        
        //create a vector
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1 , 0));

        for(int curr=n-1 ; curr>=0;curr--){
            for(int prev = curr-1;prev>=-1;prev--){
                int take=0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    take = 1 + dp[curr+1][curr+1];
                }    
                int nottake = 0 +dp[curr+1][prev+1];
                dp[curr][prev+1]= max(take,nottake);
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums.size(),nums);
    }
};

//using space optimisation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> currrow(n+1,0);
        vector<int> nextrow(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int take=0;
                if(prev == -1 || nums[curr] > nums[prev])
                    take=1+nextrow[curr+1];
                int nottake=0+nextrow[prev+1];    
                currrow[prev+1]=max(take,nottake);
            }
            nextrow=currrow;
        }
        return nextrow[0];
    }
};

//using Dp+BinarySearch
//Approach Dp with binary search
//first create a vector ans to store longest subsequence
//insert first element of given vector in ans kyuki pehle element se pehle koi element hai hi nahi na to 
//wo to ayega hi ayega
//now traverse given vector from 1 to n
//agar current element bada ho ans(vector) ke last element se to directly push kr do 
//otherwise current element ka just bada element nikalo or uski jagah current element place kr do
//one doubt obtain in everyone's mind is agr replace krne ke bad next element jo vector me already hai ya //ane wala hai wo kahi bada to chota to nahi ho jayga ..ye mistake na ho isliye humne just bade element se
//replace kiya taki koi gadbad na ho
//return ans.size()


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n == 0)
            return 0;
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i] > ans.back())
                ans.push_back(nums[i]);
            else{
                 int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];   
            }
        }    
        return ans.size();
    }
};