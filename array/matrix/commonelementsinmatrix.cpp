
// Can we do better than O(mnlogn)? 
// The idea is to use maps. We initially insert all elements of the first row in an map. For every other element in remaining rows, we check if it is present in the map. If it is present in the map and is not duplicated in current row, we increment count of the element in map by 1, else we ignore the element. If the currently traversed row is the last row, we print the element if it has appeared m-1 times before. 

#include<vector>
#include<unordered_map>
using namespace std;
    vector<int> findCommonElements(vector<vector<int>> &mat)
    {    vector<int> ans;
            unordered_map<int,int> mp;
        for(int j=0;j<mat[0].size();j++){
            mp[mat[0][j]]++;
         }
        for(int i=1;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mp[mat[i][j]] == i){
                    mp[mat[i][j]]++;
                    if(i == mat.size() && mp[mat[i][j]] == mat.size()){
                    ans.push_back(mat[i][j]);
                    }
                }
            }
        }
        return ans;
    }