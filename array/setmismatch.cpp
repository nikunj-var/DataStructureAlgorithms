// You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

// You are given an integer array nums representing the data status of this set after the error.

// Find the number that occurs twice and the number that is missing and return them in the form of an array.

/*
Approach 1: Brute Force
The most naive solution is to consider each number from 11 to nn, and traverse over the whole numsnums array to 
check if the current number occurs twice in numsnums or doesn't occur at all. We need to set the duplicate number,
dupdup and the missing number, missingmissing, appropriately in such cases respectively.
*/

/*
Approach 2: Better Brute Force
In the last approach, we continued the search process, even when we've already found the duplicate and the missing 
number. But, as per the problem statement, we know that only one number will be repeated and only one number will 
be missing. Thus, we can optimize the last approach to some extent, by stopping the search process as soon as we 
find these two required numbers.
*/

/*
Approach 3: Using Sorting
Algorithm

One way to further optimize the last approach is to sort the given numsnums array. This way, the numbers which are
equal will always lie together. Further, we can easily identify the missing number by checking if every two
consecutive elements in the sorted numsnums array are just one count apart or not.
*/

/*
Approach 4: Using Map
Algorithm/use set*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int xsum=0;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            if(s.find(val) == s.end()){
                 s.insert(val);
                 xsum+=val;
            }
            else
                ans.push_back(val);
        }
        int sum=(nums.size()*(nums.size()+1))/2;
        ans.push_back(sum-xsum);
        return ans;
    
        
    }
};

/*
Approach 5: Using Extra Array
Algorithm

In the last approach, we make use of a mapmap to store the elements of numsnums along with their corresponding 
counts. But, we can note, that each entry in mapmap requires two entries. Thus, putting up nn entries requires 2n2n 
space actually. We can reduce this space required to nn by making use of an array, arrarr instead. Now, the indices
 of arrarr can be used instead of storing the elements again. Thus, we make use of arrarr in such a way that,
  arr[i]arr[i] is used to store the number of occurences of the element i+1i+1. The rest of the process remains 
  the same as in the last approach.
*/

/*
Approach 6: Using Constant Space
Algorithm

We can save the space used in the last approach, if we can somehow, include the information regarding the duplicacy
 of an element or absence of an element in the numsnums array. Let's see how this can be done.

We know that all the elements in the given numsnums array are positive, and lie in the range 11 to nn only. Thus, 
we can pick up each element ii from numsnums. For every number ii picked up, we can invert the element at the index
 \left|i\right|∣i∣. By doing so, if one of the elements jj occurs twice, when this number is encountered the second 
 time, the element nums[\left|i\right|]nums[∣i∣] will be found to be negative. Thus, while doing the inversions, 
 we can check if a number found is already negative, to find the duplicate number.

After the inversions have been done, if all the elements in numsnums are present correctly, the resultant numsnums 
array will have all the elements as negative now. But, if one of the numbers, jj is missing, the element at the 
j^{th}j 
th
  index will be positive. This can be used to determine the missing number.

*/

/*Approach 7: Using XOR
Algorithm

Before we dive into the solution to this problem, let's consider a simple problem. Consider an array with n-1n−1 elements containing numbers from 11 to nn with one number missing out of them. Now, how to we find out this missing element. One of the solutions is to take the XOR of all the elements of this array with all the numbers from 11 to nn. By doing so, we get the required missing number. This works because XORing a number with itself results in a 0 result. Thus, only the number which is missing can't get cancelled with this XORing.

Now, using this idea as the base, let's take it a step forward and use it for the current problem. By taking the XOR of all the elements of the given numsnums array with all the numbers from 11 to nn, we will get a result, xorxor, as x^yx 
y
 . Here, xx and yy refer to the repeated and the missing term in the given numsnums array. This happens on the same grounds as in the first problem discussed above.

Now, in the resultant xorxor, we'll get a 1 in the binary representation only at those bit positions which have a 1 in one out of the numbers xx and yy, and a 0 at the same bit position in the other one. In the current solution, we consider the rightmost bit which is 1 in the xorxor, although any bit would work. Let's say, this position is called the rightmostbitrightmostbit.

If we divide the elements of the given numsnums array into two parts such that the first set contains the elements which have a 1 at the rightmostbitrightmostbit position and the second set contains the elements having a 0 at the same position, we'll get one out of xx or yy in one set and the other one in the second set. Now, our problem has reduced somewhat to the simple problem discussed above.

To solve this reduced problem, we can find out the elements from 11 to nn and consider them as a part of the previous sets only, with the allocation of the set depending on a 1 or 0 at the righmostbitrighmostbit position.

Now, if we do the XOR of all the elements of the first set, all the elements will result in an XOR of 0, due to cancellation of the similar terms in both numsnums and the numbers (1:n)(1:n), except one term, which is either xx or yy.

For the other term, we can do the XOR of all the elements in the second set as well.

*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int > ans;
       for(int i=0;i<nums.size();i++){
           if(nums[abs(nums[i]) - 1] < 0){
               ans.push_back(abs(nums[i]));
               
           }
           else{
               nums[abs(nums[i]) - 1]*=-1;
           }
       }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > 0)
                ans.push_back(i+1);
        }
        return ans;
    }
};



