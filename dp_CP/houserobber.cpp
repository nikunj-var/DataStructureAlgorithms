//all cases are copy of max non-adjacent elements


//space-optimisation
class Solution {
public:
    int rob(vector<int>& nums) {
         int prev1=nums[0];
         int prev2=0;
        for(int i=1;i<nums.size();i++){
            int incl=prev2+nums[i];
            int excl=prev1+0;
            
            int ans=max(incl,excl);
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
};