//top-down method

#include<bits/stdc++.h>
using namespace std;
int fib(int n,vector<int>& dp){
    if(n == 0 || n==1)
        return n;
    if(dp[n] != -1){
        return dp[n];
    }    
    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}
int nthfibonacci(int n){
    vector<int> dp(n+1,-1);
    int ans=fib(n,dp);
    return ans;
}

int main(){
    int n;
    cout<<"enter n ";
    cin>>n;
    cout<<nthfibonacci(n);
}

//bottom-up method

#include<bits/stdc++.h>
using namespace std;

int nthfibonacci(int n){
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];    
}

int main(){
    int n;
    cout<<"enter n ";
    cin>>n;
    cout<<nthfibonacci(n);
}

//space optimisation
#include<bits/stdc++.h>
using namespace std;

int nthfibonacci(int n){
    if(n==0 || n==1)
        return n;
    int prev1=0;
    int prev2=1;
    int curr;
    for(int i=2;i<=n;i++){
        curr=prev1+prev2;
        prev1=prev2;
        prev2=curr;
    }
    return prev2; 
}

int main(){
    int n;
    cout<<"enter n ";
    cin>>n;
    cout<<nthfibonacci(n);
}