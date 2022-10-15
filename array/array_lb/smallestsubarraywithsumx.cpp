//approach- 
/*
    // Returns length of smallest subarray with sum greater than
    // x. If there is no subarray with given sum, then returns
    // n+1

    // Initialize current sum and minimum length
  
    // Initialize starting and ending indexes
        // Keep adding array elements while current sum
        // is smaller than or equal to x
       
        // If current sum becomes greater than x.
      
            // Update minimum length if needed
            // remove starting elements
*/
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int currsum=0;
        int  minlen=n+1;
        
        int start=0;
        int end=0;
        while(end < n){
            while(currsum <= x && end<n){
                currsum+=arr[end++];
            }
            while(currsum > x && start < n){
                if(end-start < minlen){
                    minlen=end-start;
                }
                currsum-=arr[start++];
            }
        }
      
        return minlen;
    }
};