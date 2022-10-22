class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> finalans;
        vector<vector<int>> ans;
        for(int i=0;i<=rowIndex;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                if(i == j || j == 0)
                    temp.push_back(1);
                else
                    temp.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            if(i == rowIndex){
               finalans=temp;  
            }
            ans.push_back(temp);
            temp.clear();
        }
        return finalans; 
    }
};
