class Solution
{
	public:
	    vector<string>::iterator it;
	    void solve(string s,vector<string>& ans,int index){
	        if(index >= s.length()){
	            it = find (ans.begin(), ans.end(), s);
                if(it == ans.end()){
                    ans.push_back(s);
                    return;
                }
	        }
	        for(int i=index;i<s.length();i++){
	            swap(s[index],s[i]);
	            solve(s,ans,index+1);
	            swap(s[index],s[i]);
	        }
	    }
		vector<string>find_permutation(string s)
		{
		   vector<string> ans;
		   int index=0;
		   solve(s,ans,index);
		   sort(ans.begin(),ans.end());
		   return ans;
		}
};
