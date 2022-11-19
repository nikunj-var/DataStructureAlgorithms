class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long,vector<long long>,greater<long,long>> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        int cost=0;
        while(pq.size() > 1){
            auto a=pq.top();
            pq.pop();
            auto b=pq.top();
            pq.pop();
            
            int sum=(a+b);
            cost+=sum;
            pq.push(sum);
        }
        
        return cost;
    }
};