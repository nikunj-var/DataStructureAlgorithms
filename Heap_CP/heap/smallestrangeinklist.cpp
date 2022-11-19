class Node{
    public:
        int i,j,data;
        Node(int i,int j,int data){
            this->i=i;
            this->j=j;
            this->data=data;
        }
};
class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data > b->data;
    }
};
class Solution {
public:
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        priority_queue<Node*,vector<Node*>,compare> q;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i][0]);
            maxi=max(maxi,nums[i][0]);
            int element=nums[i][0];
            q.push(new Node(i,0,element));
        }
        
        int start=mini;
        int end=maxi;
        while(!q.empty()){
            auto temp=q.top();
            q.pop();
            mini=temp->data;
            
            if(maxi-mini < end-start){
                start=mini;
                end=maxi;
            }
            if(temp-> j+1 < nums[temp->i].size()){
                maxi=max(maxi,nums[temp->i][temp->j+1]);
                q.push(new Node(temp->i,temp->j+1,nums[temp->i][temp->j+1]));
            }
            else
                break;
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};