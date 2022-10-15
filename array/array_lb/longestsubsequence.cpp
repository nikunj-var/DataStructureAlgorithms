//question-Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order. 

//approach1
//using sorting 
//Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      sort(arr,arr+n);
      int maxcount=0;
      int count=1;
      int i=0;
      while(i<n){
          if(i<n-1 && (arr[i+1]==arr[i]+1 || arr[i]==arr[i+1])){
              while(i<n-1 && (arr[i+1]==arr[i]+1 || arr[i]==arr[i+1])){
                  if(arr[i]!=arr[i+1])
                    count++;
                  i++;
              }
          }
          else{
                i++;
              count=1;
              
          }
          maxcount=max(count,maxcount);
        
      }
      return maxcount;
    }

//approach2
//using priorityqueue
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      priority_queue<int,vector<int>,greater<int>> pq;
      
      int maxi=1;
      int count=1;
      for(int i=0;i<n;i++){
          pq.push(arr[i]);
      }
      
      int prev=pq.top();
      pq.pop();
      
      while(!pq.empty()){
          if(pq.top()-prev == 1){
              count++;
              prev=pq.top();
              pq.pop();
          }
          else if(pq.top()-prev > 1){
              count=1;
              prev=pq.top();
              pq.pop();
          }
          else if(pq.top()-prev == 0){
             prev=pq.top();
              pq.pop();
          }
          maxi=max(count,maxi);
          
      }
      return maxi;
    }