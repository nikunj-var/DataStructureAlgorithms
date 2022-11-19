//find the duplicate number in the array

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<mp.size();i++){
            if(mp[i] > 1)
                return i;
        }
        return -1;
    }
};