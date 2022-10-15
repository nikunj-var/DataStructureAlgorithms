//question link
//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0

#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int low=0;
        int mid=0;
        int high=nums.size()-1;   
        while(mid <= high){
            switch(nums[mid]){
                case 0:
                    swap(nums[low],nums[mid]);
                    mid++;
                    low++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid],nums[high]);
                    high--;
                    break;
            }
        }
    }
};
int main(){
    return 0;
}