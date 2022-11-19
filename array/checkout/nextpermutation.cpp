#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        
        //if the size is less than 1 return it
        if(n==0 || n==1)
            return;
        
        //initialize index with -1
        int index=-1;
        
        //find the index from last in which the nums[i-1] < nums[i]
        for(int i=n-1;i>0;i--){
            if(nums[i] > nums[i-1]){
                index=i;
                break;
            }
        }
        
        //if there is no index present then reverse the whole array
        if(index==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        //stror the index in prev
        int prev=index;
        
        
        //find the index which is greater then index-1 and lessthan equal to prev
        for(int i=index+1;i<n;i++){
            if(nums[i] > nums[index-1] && nums[i] <= nums[prev]){
                prev=i;
            }
        }
        
        //swap
        swap(nums[prev],nums[index-1]);
        
        //reverse the remaining array from index to last
        int low=index,high=n-1;
        
        while(low<=high){
            swap(nums[low],nums[high]);
            low++;
            high--;
        }        
    }
};