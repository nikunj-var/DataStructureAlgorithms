//INTERSECTION OF TWO ARRAY USING EXTRA SPACE

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> mp;
        for(int i=0;i<nums1.size();i++){
            mp.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            int key=nums2[i];
            if(mp.find(key)!=mp.end()){
                ans.push_back(nums2[i]);
                mp.erase(nums2[i]);
            }
                
        }
        return ans;
    }
};

//INTERSECTION OF TWO ARRAY WITHOUT USING EXTRA SPACE

// We are discussing four ways to solve this problem :

// Brute force: Use nested loops-O(n^2)
// Sorting and binary search-O(mlogm + mlogn)
// Sorting and two-pointer approach-O(mlogm + nlogn)
// Using a Hash Table-O(m+n) but S.C-O(n)

/*Sorting and binary search
In the brute force approach, we select elements from array A[] and linearly search for them in array B[]. We could increase the efficiency of searching the elements if we sort B[] and apply binary search to search for the elements. Binary Search takes O(logn) time complexity.

Solution Steps
Declare answer list.
Sort B[] array in increasing order.
Search for each element in A[] in the sorted array B[]
If the element if found, add it to the answer list
Return answer list
*/

/*Sorting and two-pointer approach
If both A[] and B[] are sorted, we can use a two-pointer approach. At each step, we compare one element of A[] with one element of B[]. If both are equal, we add it to the list, else we move forward.

Solution Steps
Declare the answer list.
Sort both the arrays in increasing order.
Initialize the variables i and j in the sorted array A[] and B[] respectively. i = 0 and j = 0
Run a loop while i < m and j < n (Why 'and', not 'or'?)
If A[i] == B[j], add A[i] to the list and increment both i and j
If A[i] < B[j], increase i by 1
If A[i] > B[j], increase j by 1
5. Return answer list.
*/