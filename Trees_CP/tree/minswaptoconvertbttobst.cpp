// The idea is to use the fact that inorder traversal of Binary Search Tree is in increasing order of their value. 
// So, find the inorder traversal of the Binary Tree and store it in the array and try to sort the array. The minimum number of swap required to get the array sorted will be the answer. Please refer below post to find minimum number of swaps required to get the array sorted.

class Solution{
  public:
  
    void storeinorder(vector<int>& a,vector<int>& v,int i){
        if(i >= a.size())
            return;
        storeinorder(a,v,2*i+1);
        v.push_back(a[i]);
        storeinorder(a,v,2*i+2);
    }
    int minswaps(vector<int>& v){
        vector<pair<int,int>> p(v.size());
        
        for(int i=0;i<v.size();i++)
        {
            p[i].first=v[i];
            p[i].second=i;
        }
        
        sort(p.begin(),p.end());
        
        int ans=0;
        
        for(int i=0;i<v.size();i++){
            if(p[i].second == i)
                continue;
            else{
                swap(p[i].first,p[p[i].second].first);
                swap(p[i].second,p[p[i].second].second);
            }
            if(p[i].second != i)
                i--;
            ans++;
        }
        return ans;
    }
    int minSwaps(vector<int>&a, int n){
        vector<int > v;
        storeinorder(a,v,0);
        return minswaps(v);
    }
    
    