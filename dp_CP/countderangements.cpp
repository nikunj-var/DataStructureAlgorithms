//recursion
#define mod 1000000007
long long int countDerangements(int n) {
    // Write your code here.
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    int ans=(((n-1)%mod)*(countDerangements(n-1)%mod+countDerangements(n-2)%mod))%mod;
    
    return ans;
}

//using topdown
#define mod 1000000007
#include<vector>
long long solve(int n,vector<long long>& dp){
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    dp[n]=(((n-1)%mod)*(solve(n-1,dp)%mod+solve(n-2,dp)%mod))%mod;
    return dp[n];
}
long long int countDerangements(int n) {
      vector<long long> dp(n+1,-1);
    
    return solve(n,dp);
}

//using tabular
#define mod 1000000007
#include<vector>
long long int solve(int n){
    vector<long long int> dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    
    for(int i=3;i<=n;i++){
        long long int first=dp[i-1]%mod;
        long long int second=dp[i-2]%mod;
        long long int sum=(first + second)%mod;
        long long int ans=((i-1)*sum)%mod;
        dp[i]=ans;
    }
    return dp[n];
}
long long int countDerangements(int n) {
     
    
    return solve(n);
}

//using spaceoptimisation

#define mod 1000000007
long long int countDerangements(int n) {
    long long int prev1=1;
    long long int prev2=0;
    for(int i=3;i<=n;i++){
        long long int first=prev1%mod;
        long long int second=prev2%mod;
        long long int sum=(first+second)%mod;
        long long int ans=((i-1)*sum)%mod;
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}