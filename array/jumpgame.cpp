#include<bits/stdc++.h>
using namespace std;

//approach1
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach=0;
        int i=0;
        for(;i<nums.size();i++){
            reach=max(reach,nums[i]+i);
            if(reach <= i)
                break;
        }
        if(i < nums.size()-1)
            return false;
        return true;
    }
};


//approach2
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currlen=0,maxlen=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            currlen=max(currlen,nums[i]+i);
            if(maxlen == i)
                maxlen=currlen;
            if(maxlen == n-1)
                return true;
        }
        if( maxlen < n-1)
            return false;
        return true;
        
    }
};