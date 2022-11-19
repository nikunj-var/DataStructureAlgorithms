/*The idea to solve this problem is to traverse the string on and keep track of the count of open parentheses and
 close parentheses with the help of two counters left and right respectively.
First, the string is traversed from the left towards the right and for every “(” encountered, the left counter is
 incremented by 1 and for every “)” the right counter is incremented by 1.
Whenever the left becomes equal to right, the length of the current valid string is calculated and if it greater 
than the current longest substring, then value of required longest substring is updated with current string length.
If the right counter becomes greater than the left counter, then the set of parentheses has become invalid and 
hence the left and right counters are set to 0.
After the above process, the string is similarly traversed from right to left and similar procedure is applied.*/

class Solution {
public:
    int longestValidParentheses(string s) {
      int n=s.length();
      int left=0,right=0,maxlength=0,t=2;
      while(t--){
        left=0;
        right=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')left++;
            else right++;
                 
            if(left==right){
                maxlength=max(maxlength,2*left);
            }
            //when travelling from 0 to n-1   
            if(t%2==1 && right>left){
                left=0;
                right=0;
              }
              //when travelling from n-1 to 0
              if(t%2==0 && left>right){
                  left=0;
                  right=0;
              }
            }
              //now we need to do the same thing from the other side;
            reverse(s.begin(),s.end());
        }
        return maxlength;
    }
};