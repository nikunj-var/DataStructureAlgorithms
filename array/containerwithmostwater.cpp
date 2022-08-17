
#include<bits/stdc++.h>
using namespace std;
 

class Solution {
public:
    int maxArea(vector<int>& height) {
       int area;
        int maxarea=INT_MIN;
       int start=0;
        int end=height.size()-1;
        while(start<end){
            area=min(height[start],height[end])*(end-start);
            maxarea=max(area,maxarea);
            if(height[start] < height[end])
                start++;
            else
                end--;
        }
        return maxarea;
    }
};