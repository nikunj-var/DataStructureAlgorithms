class Solution{
    public:
    void heapify(vector<int>& a,int n,int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left < n && a[largest] < a[left])
            largest=left;
        if(right < n && a[largest] < a[right])
            largest=right;
        if(largest != i)
        {
            swap(a[largest],a[i]);
            heapify(a,n,largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> c;
        for(auto i:a){
            c.push_back(i);
        }
        for(auto i:b){
            c.push_back(i);
        }
        for(int i=c.size()/2 -1 ; i>=0;i--){
            heapify(c,c.size(),i);
        }
        return c;
    }
};

