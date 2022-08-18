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
        
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int f=first(nums,0,nums.size()-1,target);
        int l=last(nums,0,nums.size()-1,target);
      
        vector<int> ans;
        
        if(f == -1 )
            return ans;
      
        for(int i=f;i<=l;i++)
            ans.push_back(i);
        
        return ans;
    }
};