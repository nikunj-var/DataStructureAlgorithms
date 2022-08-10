// Given a binary array nums, return the maximum number of consecutive 1's in the array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1=INT_MIN;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                maxi++;
            }
            else{
                max1=max(maxi,max1);
                maxi=0;
            }
        }
        return max(maxi,max1);
    }
};