// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int,int> mp;
       vector<int> ans;
       
        for(int i=0;i<nums.size();i++){
           mp[nums[i]]=i;
       }  
       
        for(int i=0;i<nums.size();i++){
            bool flag=false;
            if(mp[target-nums[i]] && mp[target-nums[i]] != i){
                  flag=true;
            }
            if(flag){
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                break;
            }
        }
        return ans;
    }
};