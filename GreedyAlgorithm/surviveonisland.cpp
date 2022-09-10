class Solution{
public:
    int minimumDays(int s, int n, int m){
        if(n < m)
            return -1;
        int sunday=s/7;
        int buyingdays=s-sunday;
        int totalfood=s*m;
        int ans=0;
        
        if(totalfood % n == 0)
        {
            ans=totalfood/n;
        }
        else{
            ans=totalfood/n+1;
        }
        
        if(buyingdays >= ans)
            return ans;
        else
            return -1;
    }
};