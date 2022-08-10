// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.

// Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

// Return k after placing the final result in the first k slots of nums.

// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.


#include<vector>
#include<map>
using namespace std;


//take more time
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return nums.size();
        
       vector<int> :: iterator it;
        
       for(int i=0;i<nums.size();){
           if(i+1 <nums.size() && nums[i] == nums[i+1])
           {
               int j=i;
               i++;
               while(i < nums.size() && nums[i]==nums[j]){
                    it = nums.begin() + i;
                    nums.erase(it);
                    
                 }
             }
            else
                i++;     
          }
        return nums.size();
    }
};

//take less time TC_O(n)
//using two pointer approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return nums.size();
        
        int left=0;
        int right=0;
        while(right < nums.size()){
            if(nums[left] != nums[right]){
                left++;
            }
            nums[left]=nums[right];
            right++;
        }
        return left+1;
    }
};