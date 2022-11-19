#include <bits/stdc++.h>
using namespace std;



class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        //create a map and store all the elements in map
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }


        int count=0;
        //search if the pair exist or not
        for(int i=0;i<n;i++){
           count+=mp[k-arr[i]];
           
           //if a number stores itself then remove it from count
           if(k-arr[i]==arr[i])
             count--;
       }
       //since all the pairs are added twice that's why divide the count by 2
       return count/2;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
