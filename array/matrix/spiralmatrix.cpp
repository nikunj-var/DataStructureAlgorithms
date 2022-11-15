 #include<vector>
 using namespace std;
 
 vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
       int rowstart=0,colstart=0,rowend=r-1,colend=c-1;
       vector<int> ans;
       while(rowstart <= rowend && colstart <= colend){
           for(int i=colstart ; i <= colend ; i++){
               ans.push_back(matrix[rowstart][i]);
            }
            rowstart++;
            if(ans.size()>=r*c)
                break;
           for(int i= rowstart;i<=rowend;i++){
               ans.push_back(matrix[i][colend]);
           }
           colend--;
             if(ans.size()>=r*c)
            break;
           for(int i=colend;i >= colstart;i--){
               ans.push_back(matrix[rowend][i]);
           }
           rowend--;
             if(ans.size()>=r*c)
            break;
           for(int i=rowend;i>=rowstart;i--){
               ans.push_back(matrix[i][colstart]);
           }
           colstart++;
             if(ans.size()>=r*c)
            break;
       }
       return ans;
    }
