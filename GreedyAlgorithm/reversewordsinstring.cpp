class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        string ans="";
        string temp="";
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == '.'){
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+='.';
                temp="";
            }
            else
                temp+=s[i];
        }
         reverse(temp.begin(),temp.end());
                ans+=temp;
    return ans;
        
    } 
};