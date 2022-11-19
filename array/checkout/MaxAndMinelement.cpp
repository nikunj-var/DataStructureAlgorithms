//find the sum of maximum and minimum element in the array

#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

class Solution
{
   public:
    int findSum(int arr[], int n)
    {   
        int maxi=INT_MIN;
        int mini=INT_MAX;
    	//function to find the minimum and maximum elements
    	for(int i=0;i<n-1;i++){
    	    if(arr[i] < arr[i+1]){
    	        maxi=max(arr[i+1],maxi);
    	        mini=min(arr[i],mini);
    	    }
    	    else{
    	        maxi=max(arr[i],maxi);
    	        mini=min(arr[i+1],mini);
    	    }
    	}
    	return mini+maxi;
    }
};