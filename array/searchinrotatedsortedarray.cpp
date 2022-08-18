
#include<bits/stdc++.h>
using namespace std;
 
//approach1
//without pivot element
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int mid=low+(high-low)/2;
        
        while(low <= high){
            if(nums[mid] == target)
                return mid;
            
            
            else if(nums[low] <= nums[mid]){
                if(nums[low] <= target && nums[mid] > target)
                    high=mid-1;
                else
                    low=mid+1;
            }
            
            else if(nums[mid] <= nums[high]){
                if(nums[mid] < target && nums[high] >= target){
                    low=mid+1;
                }
                else
                    high=mid-1;
            }
            
            mid=low+(high-low)/2;
        }
        return -1;
    }
};

//approach2
//with pivot element

class Solution {
public:
    int findpivot(vector<int> &nums){
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<e){
            if(nums[mid] >= nums[0])
                s=mid+1;
            else
                e=mid;
            mid=s+(e-s)/2;
        }
        return s;
    }
    int binarysearch(vector<int>& nums,int s,int e,int target){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                s=mid+1;
            else
                e=mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot=findpivot(nums);
         
        if(nums[pivot] <= target && nums[nums.size()-1] >= target)
            return binarysearch(nums,pivot,nums.size()-1,target);
        return binarysearch(nums,0,pivot-1,target);
    }
};