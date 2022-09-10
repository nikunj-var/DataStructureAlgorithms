class Solution{
    public:
    long long findMinDiff(vector<long long> arr, long long n, long long m){
       long long mindiff=INT_MAX;
       long long diff;
       sort(arr.begin(),arr.end());
       for(int i=0;i+m-1 < n ;i++){
           diff=arr[i+m-1] - arr[i];
           mindiff=min(mindiff,diff);
       }
       return mindiff;
    }   
};
