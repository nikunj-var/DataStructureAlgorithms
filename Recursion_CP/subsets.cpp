// read the question by copying this link
// https://leetcode.com/problems/subsets/

class Solution {
public:
    //solution using recursion
    void solve(vector<int>& nums, vector<int> output,int index, vector<vector<int>>& ans){
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        //call exclude 
        //it means we are not pushing anything in the output array
        solve(nums,output,index+1,ans);
        
        //element stores value at index in the array
        int element=nums[index];
        //put it into the output array
        output.push_back(element);
        
        //call include
        //it means we are traversing reversively and also store the values in the array
        solve(nums,output,index+1,ans);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
     
        //if vector is empty return it
        if(nums.size()==0)
            return ans;
        
        vector<int> output;
        
        int index=0;
        
        //call function
        solve(nums,output,index,ans);
        
        return ans;
    }
};