//using recursion
class Solution {
public:
    int solve(string &a,string &b,int i,int j){
        if(a.length() == i){
            return b.length()-j;
        }
        if(b.length() == j){
            return a.length()-i;
        }

        int ans=0;
        if(a[i] == b[j])
            return solve(a,b,i+1,j+1);
        else{
            //insert
            int insert=1+solve(a,b,i,j+1);
            //delete
            int deletec=1+solve(a,b,i+1,j);
            //replace
            int replace=1+solve(a,b,i+1,j+1);

            ans=min(insert,min(deletec,replace));
        } 
        return ans;
    }
    int minDistance(string word1, string word2) {
        return solve(word1,word2,0,0);
    }
};

//using recursion and memoization
class Solution {
public:
    int solve(string &a,string &b,int i,int j,vector<vector<int>>& dp){
        if(a.length() == i){
            return b.length()-j;
        }
        if(b.length() == j){
            return a.length()-i;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans=0;
        if(a[i] == b[j])
            return solve(a,b,i+1,j+1,dp);
        else{
            //insert
            int insert=1+solve(a,b,i,j+1,dp);
            //delete
            int deletec=1+solve(a,b,i+1,j,dp);
            //replace
            int replace=1+solve(a,b,i+1,j+1,dp);

            ans=min(insert,min(deletec,replace));
        } 
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2,0,0,dp);
    }
};

//using tabulation
class Solution {
public:
    int solve(string &a,string &b){
        vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,0));
        for(int j=0;j<b.length();j++){
            dp[a.length()][j]=b.length()-j;
        }
        for(int j=0;j<a.length();j++){
            dp[j][b.length()]=a.length()-j;
        }
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                 int ans=0;
                if(a[i] == b[j])
                    dp[i][j]=dp[i+1][j+1];
                else{
                    //insert
                    int insert=1+dp[i][j+1];
                    //delete
                    int deletec=1+dp[i+1][j];
                    //replace
                    int replace=1+dp[i+1][j+1];
                    ans=min(insert,min(deletec,replace));
                    dp[i][j]=ans;
                }
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
       return solve(word1,word2);
    }
};
//using space optimisation
class Solution {
public:
    int solve(string &a,string &b){
        vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,0));
        vector<int> curr(b.length()+1,0);
        vector<int> next(b.length()+1,0);
        for(int j=0;j<b.length();j++){
            next[j]=b.length()-j;
        }
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                curr[b.length()]=a.length()-i;
                int ans=0;
                if(a[i] == b[j])
                    ans=next[j+1];
                else{
                    //insert
                    int insert=1+curr[j+1];
                    //delete
                    int deletec=1+next[j];
                    //replace
                    int replace=1+next[j+1];
                    ans=min(insert,min(deletec,replace));
                }
                 curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        if(word1.length() == 0)
            return word2.length();
        if(word2.length() == 0)
            return word1.length();    
       return solve(word1,word2);
    }
};