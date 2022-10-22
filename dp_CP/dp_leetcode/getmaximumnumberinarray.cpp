class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0 || n==1)
            return n;
        vector<int> nums(n+1,0);
        nums[0]=0;
        nums[1]=1;

        int k=1;
        while(k <= n/2){
            if(k*2 > n || k*2+1 > n)
                break;
            nums[(k*2)]=nums[k];
            nums[(k*2)+1]=nums[k]+nums[k+1];
            k++;
        }    
        int maxi=INT_MIN;
        for(int i=0;i<=n;i++){
            maxi=max(maxi,nums[i]);
        }
        return maxi;
    }
};