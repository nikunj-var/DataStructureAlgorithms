#include<vector>
#include<algorithm>
using namespace std;
class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<R;i++){
            mini=min(mini,matrix[0][i]);
            maxi=max(maxi,matrix[i][C-1]);
        }
        int desired=(R*C+1)/2;
        while(mini < maxi){
            int mid=mini+(maxi-mini)/2;
            int place=0;
            
            for(int i=0;i<R;i++){
                place+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if(place < desired){
                mini=mid+1;
            }
            else{
                maxi=mid;
            }
        }
        return mini;
    }
};