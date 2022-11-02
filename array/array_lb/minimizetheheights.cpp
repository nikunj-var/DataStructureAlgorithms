https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// gives runtime eror

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        vector<int> taken(n);
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            if(arr[i]-k >= 0)
                v.push_back({arr[i]-k , 0});
            v.push_back({arr[i]+k , i});    
        }
        sort(v.begin(),v.end());
        int element=0;
        int left=0;
        int right=0;
        while(element < n && right < v.size()){
            if(taken[v[right].second] == 0)
                element++;
            taken[v[right].second]++;    
        }
        int ans=v[right-1].first-v[left].first;
        while(right < v.size()){
            if(taken[v[left].second] == 1)
                element--;
            taken[v[left].second]--;
            left++;
        while(element < n && right < v.size()){
            if(taken[v[right].second] == 0)
                element++;
            taken[v[right].second]++;    
        }
        if(element == n){
            ans=min(ans,v[right-1].first-v[left].first);
        }
        else break;
            
        }
        return ans;
    }
};