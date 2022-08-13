/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
*/

#include<bits/stdc++.h>
using namespace std;
 
//approach1
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        k=k%nums.size();
        
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

//approach2
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==1||nums.size()==0)
            return;
        vector<int > ans;
        k=k%nums.size();
        for(int i=nums.size()-k;i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        for(int i=0;i<nums.size()-k;i++){
            ans.push_back(nums[i]);
        }
        nums.clear();
        for(int i=0;i<ans.size();i++){
            nums.push_back(ans[i]);
        }
        ans.clear();
    }
};