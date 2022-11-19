

class Solution
{
    public:
    class node{
        public:
            int i,j,d;
            node(int i,int j,int d){
                this->i=i;
                this->j=j;
                this->d=d;
            }
    };
    class compare{
        public:
            bool operator()(node* a,node* b){
                return a->d > b->d;
            }
    };
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<node*,vector<node*>,compare> q;
        for(int i=0;i<arr.size();i++){
            node* temp=new node(i,0,arr[i][0]);
            q.push(temp);
        }
        vector<int> ans;
        while(!q.empty()){
            node* temp=q.top();
            q.pop();
            ans.push_back(temp->d);
            int row=temp->i;
            int col=temp->j;
            if(col+1 < arr.size()){
                 node* temp=new node(row,col+1,arr[row][col+1]);
                 q.push(temp);
            }
        }
        return ans;
    }
};
