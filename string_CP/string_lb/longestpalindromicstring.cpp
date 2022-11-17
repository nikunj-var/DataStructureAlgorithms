class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int n=s.length();
        int len=0;  //to store maximum palindromic string length
        int l,r;
        for(int i=0;i<s.length();i++){
            l=i;
            r=i;
            //for odd length
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r-l+1 > len){
                    len = r-l+1;
                    ans=s.substr(l,len);
                }
                l--;
                r++;
            }

            //for even length
            l=i;
            r=i+1;
            while(l >= 0 && r<n && s[l] == s[r]){
                if(r-l+1 > len){
                    len=r-l+1;
                    ans=s.substr(l,len);
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};