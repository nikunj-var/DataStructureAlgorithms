#include<vector>
#include<stack>
using namespace std;


class Solution {
public:
    vector<int> nextsmall(vector<int > arr,int n){
        vector<int> ans(n,0);
        stack<int> s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(s.top()!=-1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevsmall(vector<int > arr,int n){
        vector<int> ans(n,0);
        stack<int> s;
        s.push(-1);
        
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(s.top()!=-1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    
    int largestrectangle(vector<int> heights){
        int area=INT_MIN;
        int n=heights.size();
        vector<int> next(n),prev(n);
        next=nextsmall(heights,n);
        prev=prevsmall(heights,n);
        for(int i=0;i<n;i++){
            int l=heights[i];
            
             //this is because if all the elements of the array are equal
            if(next[i]==-1)
                next[i]=n;
            
            int b=next[i]-prev[i]-1;
            int newarea=l* b;
            area=max(area,newarea);
        }
        return area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<int> ans(matrix[0].size(),0);
        int area=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0')
                   ans[j]=0;
                else
                   ans[j]=ans[j]+1;
            }
            area=max(area,largestrectangle(ans));
        }
       return area;
    }
};