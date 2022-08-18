#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int curreach=0;
        int maxreach=0;
        for(int i=0;i<nums.size()-1;i++){
            maxreach=max(maxreach,nums[i]+i);
            if(i == curreach)
            {
                jumps++;
                curreach=maxreach;
            }
        
        }
        return jumps;
    }
};