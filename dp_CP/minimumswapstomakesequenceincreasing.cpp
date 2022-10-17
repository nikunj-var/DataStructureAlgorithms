//using recursion
class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int index,bool swapped){
        //base case
        if(index == nums1.size())
            return 0;

        int prev1=nums1[index-1];
        int prev2=nums2[index-1];

        //catch condition
        if(swapped){
            swap(prev1,prev2);
        }    
        int ans=INT_MAX;
        
        //noswap
        if(prev1 < nums1[index] && prev2 < nums2[index])
            ans=solve(nums1,nums2,index+1,0);

        //swap
        if(prev2 < nums1[index] && prev1 < nums2[index])
            ans=min(ans,1+solve(nums1,nums2,index+1,1));    

        return ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);

        bool swapped=0;
        return solve(nums1,nums2,1,swapped);
    }
};

//using recursion and memoization
class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int index,bool swapped,vector<vector<int>>& dp){
        //base case
        if(index == nums1.size())
            return 0;

        if(dp[index][swapped] != -1)
            return dp[index][swapped];

        int prev1=nums1[index-1];
        int prev2=nums2[index-1];

        //catch condition
        if(swapped){
            swap(prev1,prev2);
        }    
        int ans=INT_MAX;
        
        //noswap
        if(prev1 < nums1[index] && prev2 < nums2[index])
            ans=solve(nums1,nums2,index+1,0,dp);

        //swap
        if(prev2 < nums1[index] && prev1 < nums2[index])
            ans=min(ans,1+solve(nums1,nums2,index+1,1,dp));    

        return dp[index][swapped]=ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        vector<vector<int>> dp(nums1.size()+1,vector<int>(2,-1));
        bool swapped=0;
        return solve(nums1,nums2,1,swapped,dp);
    }
};

//using tabulation
class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2){
        vector<vector<int>> dp(nums1.size()+1,vector<int>(2,0));
        for(int index = nums1.size()-1;index >= 1 ;index--){
            for(int swapped = 1;swapped >=0;swapped--){
                int ans=INT_MAX;
                int prev1=nums1[index-1];
                int prev2=nums2[index-1];

                //catch condition
                if(swapped){
                    swap(prev1,prev2);
                }            
                //noswap
                if(prev1 < nums1[index] && prev2 < nums2[index])
                    ans=dp[index+1][0];
                //swap
                if(prev2 < nums1[index] && prev1 < nums2[index])
                    ans=min(ans,1+dp[index+1][1]);
                dp[index][swapped]=ans;
            }
        }
        return dp[1][0];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return solve(nums1,nums2);
    }
};