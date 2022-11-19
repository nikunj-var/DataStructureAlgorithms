// Sort the intervals array according to startTime.
// Create an array to store the merged intervals.
// If the current and previous intervals does not overlap each other, append the current interval to the merged array.
// Else, merge both previous and current intervals and insert it into the merged array.



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(ans.empty() || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};