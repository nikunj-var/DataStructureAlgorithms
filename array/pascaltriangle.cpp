// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
      
    vector<vector<int>> generate(int numRows) {
         vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                if(i == j || j == 0)
                    temp.push_back(1);
                else
                    temp.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
