class Solution {
  public:
    int solve(int coins[], int n, int sum){
       if(sum == 0)
            return 1;
       if(sum < 0 || n <= 0)
            return 0;
        int ans;
        for(int i=0;i<n;i++){
            int incl=solve(coins,n,sum-coins[i]);
            int excl=solve(coins,n-1,sum);
            ans=incl+excl;
        }
        return ans;
    }
    long long int count(int coins[], int N, int sum) {
        return solve(coins,N,sum);

    }
};