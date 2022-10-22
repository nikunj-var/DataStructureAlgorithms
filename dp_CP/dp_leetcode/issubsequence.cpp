class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l1=s.length();
        int l2=t.length();
        int i=0;
        int j=0;

        while(i<l1 && j<l2){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }
        if(i == l1)
            return true;
        return false;    
    }
};