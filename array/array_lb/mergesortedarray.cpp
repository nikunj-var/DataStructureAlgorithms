// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)
            return;
        if(m == 0){
            nums1=nums2;
            return;
        }
        int i=m-1;
        int j=n-1;
        int k=(m+n)-1;
        
        while(i>=0 && j>=0){
            if(nums2[j] <= nums1[i]){
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else{
                nums1[k]=nums2[j];
                k--;
                j--; 
            }
        }
        while(i>=0){
             nums1[k]=nums1[i];
                i--;
                k--; 
        }
        while(j>=0){
            nums1[k]=nums2[j];
                k--;
                j--; 
        }
        
    }
};