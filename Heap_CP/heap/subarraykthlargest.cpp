
class Solution{
public:
    int kthLargest(vector<int> &arr,int n,int k){
        priority_queue<int,vector<int>,greater<int>> q;
        
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(q.size() < k){
                    q.push(sum);
                }
                else{
                    if(sum > q.top()){
                        q.pop();
                        q.push(sum);
                    }
                }
            }
        }
        return q.top();
    }
};