// approach : using hashing
/*The idea is to iterate through the array and for every element arr[i], calculate the sum of elements from 0 to i
(this can simply be done as sum += arr[i]). If the current sum has been seen before, then there is a zero-sum array.
 Hashing is used to store the sum values so that sum can be stored quickly and find out whether the current sum is
  seen before or not.

Follow the given steps to solve the problem:

Declare a variable sum, to store the sum of prefix elements
Traverse the array and at each index, add the element into the sum and check if this sum exists earlier. If the
 sum exists, then return true
Also, insert every prefix sum into a map, so that later on it can be found whether the current sum is seen before
or not
At the end return false, as no such subarray is found
*/
class Solution
{
public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int, int> mp;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (sum == 0 || mp[sum])
                return true;

            mp[sum]++;
        }
        return false;
    }
};