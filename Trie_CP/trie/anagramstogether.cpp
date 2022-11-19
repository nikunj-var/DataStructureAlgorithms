class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& s) {
        //code here
        
        unordered_map<string,vector<string>> m;
        for(int i=0;i<s.size();i++){
            string str=s[i];
            sort(str.begin(),str.end());
            m[str].push_back(s[i]);
        }
        vector<vector<string> > ans(m.size());
        int idx=0;
        for(auto i:m){
            auto v=i.second;
            for(int j=0;j<v.size();j++){
                ans[idx].push_back(v[j]);
            }
            idx++;
        }
        return ans;
    }
};