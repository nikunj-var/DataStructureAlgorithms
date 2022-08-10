#include<vector>
#include<algorithm>
#include<map>
using namespace std;


class Solution {
public:
    int binarysearch(vector<int>& nums,int low,int high,int target){
        int ans;
        //traverse until low is less than equal to high
        while(low <= high){
             int mid=low+(high-low)/2;
           
            if(nums[mid] == target){
                ans=mid;
                break;
            }
            else if(nums[mid] < target){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }

    int searchInsert(vector<int>& nums, int target) {
        
        //if target is less than first element of array then return 0
        if(target <= nums[0])
            return 0;
        //if target is greater than last element of array then return size of array
        if(target > nums[nums.size()-1])
            return nums.size();
       
        //appply binary search
            return binarysearch(nums,0,nums.size()-1,target);
    }
};