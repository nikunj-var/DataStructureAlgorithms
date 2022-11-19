/*Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers.


Example 1:

Input:
N = 6
Arr[] = {6, 8, 4, 5, 2, 3}
Output: 604
Explanation: The minimum sum is formed 
by numbers 358 and 246.*/

//approach1-using sorting
    string solve(int arr[], int n) {
        sort(arr,arr+n);
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(i % 2 == 0){
                a = a* 10 + arr[i];
            }
            else{
                b = b * 10 + arr[i];
            }
        }
        int sum=a+b;
        return to_string(sum);
    }

//approach2-using strings
/*Sort the array in increasing order
Declare two strings a and b, representing the two numbers to be formed
Traverse the array and if the index is odd then add this element into string a, else add it to the string b
Return the sum of two strings, in the form of a string*/

string solve(int arr[], int n)
{
 
    sort(arr, arr + n);
 
    // Two String for storing our two minimum numbers
    string a = "", b = "";
 
    for (int i = 0; i < n; i += 2) {
        a += (arr[i] + '0');
    }
    for (int i = 1; i < n; i += 2) {
        b += (arr[i] + '0');
    }
 
    int j = a.length() - 1;
    int k = b.length() - 1;
 
    // as initial carry is zero
    int carry = 0;
    string ans = "";
    while (j >= 0 && k >= 0) {
        int sum = 0;
        sum += (a[j] - '0') + (b[k] - '0') + carry;
        ans += to_string(sum % 10);
        carry = sum / 10;
        j--;
        k--;
    }
 
    // If string b is over and string a is left
    // here we dont need to put here while condition
    // as it would run at max one time. Because the
    // difference between both the strings could be at
    // max 1.
    while (j >= 0) {
        int sum = 0;
        sum += (a[j] - '0') + carry;
        ans += to_string(sum % 10);
        carry = sum / 10;
        j--;
    }
 
    // If string a is over and string b is left
    while (k >= 0) {
        int sum = 0;
        sum += (b[k] - '0') + carry;
        ans += to_string(sum % 10);
        carry = sum / 10;
        k--;
    }
    // if carry is left
    if (carry) {
        ans += to_string(carry);
    }
 
    // to remove leading zeroes as they will be ahead of our
    // sum
    while (!ans.empty() and ans.back() == '0')
        ans.pop_back();
 
    // reverse our final string because we were storing sum
    // from left to right
    reverse(ans.begin(), ans.end());
    return ans;
}
 