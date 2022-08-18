#include<bits/stdc++.h>
using namespace std;

//approach1-using xor
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int a=nums[0];
        
        for(int i=1;i<nums.size();i++){
            a^=nums[i];
        }
        return a;
    }
};

//approach2-using binarysearch
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // ios_base::sync_with_stdio(0);
        // cin.tie(0);
        // cout.tie(0);
        int n = nums.size();
        
        if(n == 1)
        {
            return nums[0];
        }
        if(nums[0] != nums[1])
        {
            return nums[0];
        }
        if(nums[n-1] != nums[n-2])
        {
            return nums[n-1];
        }
        
        int low = 0;
        int high = n;
        while(low<high)
        {
            int mid = low + (high - low)/2;
            if((mid&1 && nums[mid] == nums[mid-1]) || (!(mid&1) && nums[mid] == nums[mid+1]))
            {
                low = mid+1;          
            }
            else
            {
                high = mid;
            }
        }
        return nums[low];
    }
};