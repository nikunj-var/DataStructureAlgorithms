class Solution
{
    public:
    priority_queue<int> mxq;
    priority_queue<int,vector<int>,greater<int>> mnq;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(mxq.empty() == true || mxq.top() > x){
            mxq.push(x);
        }
        else{
            mnq.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(mxq.size() > mnq.size()+1){
            mnq.push(mxq.top());
            mxq.pop();
        }
        else if(mnq.size() > mxq.size() +1){
            mxq.push(mnq.top());
            mnq.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(mxq.size() == mnq.size())
            return (mnq.top()+mxq.top())/2.0;
        else{
            if(mxq.size() > mnq.size())
                return (double)mxq.top();
            else
                return (double)mnq.top();
        }
    }
};