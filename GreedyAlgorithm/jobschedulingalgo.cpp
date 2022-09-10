class Solution 
{
    public:
    static bool cmp(Job a,Job b){
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        int maxideadline=INT_MIN;
        for(int i=0;i<n;i++){
            maxideadline=max(maxideadline,arr[i].dead);
        }
        vector<int> schd(maxideadline+1,-1);
        int count=0;
        int maxprofit=0;
        for(int i=0;i<n;i++){
            int currprofit=arr[i].profit;
            int currjobid=arr[i].id;
            int currjobdead=arr[i].dead;
            
            for(int j=currjobdead;j>0;j--){
                if(schd[j] == -1){
                    count++;
                    maxprofit+=currprofit;
                    schd[j]=currjobid;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(maxprofit);
        return ans;
    } 
};
