// Given an integer array nums, handle multiple queries of the following type:

// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

//APPROACH1-

#include<bits/stdc++.h>
using namespace std;
class NumArray {
public:
    vector<int > arr;
    int sum=0;
    NumArray(vector<int>& nums) {
        arr=nums;
        sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            arr[i]=sum;
        }
    }
    
    int sumRange(int left, int right) {
        return left==0?arr[right]:arr[right]-arr[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

//APPROACH2-
class NumArray {
public:
    vector<int > arr;
    int sum=0;
    NumArray(vector<int>& nums) {
        arr=nums;
        sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int res=sum;
        for(int i=0;i<left;i++){
            res-=arr[i];
        }   
        for(int i=right+1;i<arr.size();i++){
            res-=arr[i];
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */