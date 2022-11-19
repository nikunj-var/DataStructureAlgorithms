//find the triplets whose sum is equal to 0.

#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        int n = arr.size();
        if(n == 0)
            return res;
        
        for(int i = 0;i < n-2;i++){
            if(i!=0 && arr[i]==arr[i-1]){
                continue;
            }
            int j=i+1;
            int k=n-1;
            
            while(j < k){
                
                int sum=arr[i]+arr[j]+arr[k];
                
                if(sum == 0){
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    res.push_back(temp);
                    j++;
                    k--;
                
                    while(j < k && arr[j]==arr[j-1])
                        j++;
                    
                    while(j < k && arr[k]==arr[k+1])
                        k--;
                }
                else if(sum < 0)
                    j++;
                else
                    k--;
            }    
        }
        return res;
    }
};