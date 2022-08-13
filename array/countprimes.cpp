//USING SIEVE OF ERAOSTHESES

#include<bits/stdc++.h>
using namespace std;
 
 class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1 || n==2)
            return 0;
      
        vector<bool> isprime(n+1,true);
        // vector<int> ans;
        isprime[0]=isprime[1]=false;
        int count=0;
        for(int i=2;i<n;i++){
            if(isprime[i]){
                //ans.push_back(i
                count++;
                for(int j=2*i;j<n;j+=i){
                    isprime[j]=false;
                }
            }
        }
        return count;
    }
};