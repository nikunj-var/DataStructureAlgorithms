/*Given a binary matrix your task is to find all unique rows of the given matrix.

Example 1:

Input:
row = 3, col = 4 
M[][] = {{1 1 0 1},{1 0 0 1},{1 1 0 1}}
Output: 1 1 0 1 $1 0 0 1 $
Explanation: Above the matrix of size 3x4
looks like
1 1 0 1
1 0 0 1
1 1 0 1
The two unique rows are 1 1 0 1 and
1 0 0 1 .
*/


vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{   unordered_map<string , int> m;
    string s="";
    vector<vector<int>> ans;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            s+=(M[i][j]);
        }
        if(!m[s]){
            m[s]++;
            vector<int> temp;
            for(int k=0;k<s.length();k++)
                temp.push_back(s[k]);
            ans.push_back(temp);
        }
        s="";
    }
    return ans;
}