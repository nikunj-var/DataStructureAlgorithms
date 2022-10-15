class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int *profit=new int[n];
        for(int i=0;i<n;i++)
            profit[i]=0;
        int maxprice=prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(maxprice < prices[i])
                maxprice=prices[i];
            profit[i]=max(profit[i+1],maxprice - prices[i]);
        }
        int minprice=prices[0];
        for(int i=1;i<n;i++){
            if(minprice > prices[i]){
                minprice=prices[i];
            }
            profit[i]=max(profit[i-1] , profit[i]+(prices[i]-minprice));
        }
        return profit[n-1];
    }
};