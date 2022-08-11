//Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must
//appear as many times as it shows in both arrays and you may return the result in any order.

//approach1
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            if(mp[nums2[i]]){
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return ans;
    }
};

//approach2
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
          vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        if(m>n)
        {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        sort(nums1.begin(),nums1.end());
        for(int i = 0;i<nums2.size();i++)
        {
            int key = nums2[i];
            int low = 0;
            int high = nums1.size()-1;
            while(low<=high)
            {
                int mid = low+ (high - low)/2;
                if(nums1[mid] == key)
                {
                    ans.push_back(nums1[mid]);
                    nums1.erase(nums1.begin()+mid);
                    break;
                }
                else if(nums1[mid]>key)
                {
                    high = mid-1;
                }
                else
                    low = mid+1;
            }
        }
        return ans;
    }
};