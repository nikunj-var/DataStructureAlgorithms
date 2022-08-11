// You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

// The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

// The 1st place athlete's rank is "Gold Medal".
// The 2nd place athlete's rank is "Silver Medal".
// The 3rd place athlete's rank is "Bronze Medal".
// For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
// Return an array answer of size n where answer[i] is the rank of the ith athlete.

#include<bits/stdc++.h>
using namespace std;
 


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size());
        
        priority_queue<pair<int,int>> pq;
    
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        
        int i=0;
        
        while(!pq.empty()){
            ans[pq.top().second] = (i==0) ? "Gold Medal" : (i==1) ? "Silver Medal" : (i==2) ? "Bronze Medal" :                      to_string(i+1);
            i++;
            pq.pop();
        }
        return ans;
    }
};