#include<bits/stdc++.h>
using namespace std;
 

class Solution {
public:
    
    int first(vector<int>& nums,int s,int e,int target){
        int mid=s+(e-s)/2;
        int pos=-1;
        while(s <= e){
            if(nums[mid] == target){
                pos=mid;
                e=mid-1;
            }
            else if(nums[mid] < target){
                s=mid+1;
            }
            else
                e=mid-1;
             mid=s+(e-s)/2;
        }
        return pos;
    }
    
    int last(vector<int>& nums,int s,int e,int target){
        int mid=s+(e-s)/2;
        int pos=-1;
        while(s <= e){
            if(nums[mid] == target){
                pos=mid;
                s=mid+1;
            }
            else if(nums[mid] < target){
                s=mid+1;
            }
            else
                e=mid-1;
             mid=s+(e-s)/2;
        }
        return pos;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int f=first(nums,0,nums.size()-1,target);
        int l=last(nums,0,nums.size()-1,target);
        vector<int > ans;
        ans.push_back(f);
        ans.push_back(l);
        return ans;
    }
};