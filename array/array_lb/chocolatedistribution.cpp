// Given an array of n integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 

// Each student gets one packet.
// The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.

//approach-first sort the array then take the m size window and each window find the difference between the max and min value

    long long findMinDiff(vector<long long> arr, long long n, long long m){
        long long mindiff=INT_MAX;
        long long diff=0;
        
        //sort the array
        sort(arr.begin(),arr.end());
        
        
        //find the min difference between max and min number in the window
        for(int i=0;i+m-1 < n;i++){
            diff=arr[i+m-1]-arr[i];
            mindiff=min(mindiff,diff);
        }
        return mindiff;
    
    } 