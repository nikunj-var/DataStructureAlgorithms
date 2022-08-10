// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.


#include<vector>
#include<algorithm>
#include<map>
using namespace std;
//APPROACH1 - USING MATHEMATICAL TECHNIQUE

class Solution {
public:
int missingNumber(vector<int>& nums) {
int n=nums.size();
int sum=0;
sum=(n*(n+1))/2;
int lsum=0;
for(auto i:nums){
lsum+=i;
}
return sum-lsum;
}
};

//APPROACH2- USING XOR

class Solution {
public:
int missingNumber(vector<int>& nums) {
int ans=0;
for(auto i:nums){
ans^=i;
}
for(int i=1;i<=nums.size();i++){
ans^=i;
}
return ans;
}
};