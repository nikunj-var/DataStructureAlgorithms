//Efficient Approach:  We can use the two-pointer technique and a sliding window.

//Find the count of all elements which are less than or equal to ‘k’. Let’s say the count is ‘cnt’
//Using the two-pointer technique for a window of length ‘cnt’, each time keep track of how many elements in this
// range are greater than ‘k’. Let’s say the total count is ‘bad’.
//Repeat step 2, for every window of length ‘cnt’ and take a minimum of count ‘bad’ among them. This will be the
// final answer.

//approach2-
// Another approach for solving this problem is just using a simple Sliding window technique without using any 
//pointers which can be done in O(N) time

// We will name our sliding window as snowballs. Our snowballs will be a number of elements less than or equal to K.
// Swap variable will start from 0 and we will increase its size as we encounter any element greater than K. 
// If we see an element arr[i] value greater than k, we will increase the swap else we will decrease it.
// we will keep the count variable to keep track of the number of swaps and also min_count is required to store the
// minimum value of count.


/*approach-sbse phle jitne k se elements chote hai unka count nikal lo uske bad us size ki phli window me jitne bhi 
    elements k se bade ho use count kr lo , fir do pointer lo i and j
    i ko point karao 0 pe or j ko point karao count pe fir uske bad i or j ko ek ek aage badate jao 
    i ko exclude krte jao or j ko include krte jao agr i bada ho k se to bad-- or j bada ho k se to bad++
    fir minimum return kr do*/
class solution{
public:
    int minSwap(int arr[], int n, int k) {
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i] <= k)
                count++;
        }
        int bad=0;
        for(int i=0;i<count;i++){
            if(arr[i] > k)
                bad++;
        }
        int ans=bad;
        for(int i=0,j=count;j<n;++i,++j){
            cout<<i<<" "<<j<<endl;
            if(arr[i] > k)
                --bad;
            if(arr[j] > k)
                ++bad;
            
            ans=min(ans,bad);    
        }
        return ans;
    }
};