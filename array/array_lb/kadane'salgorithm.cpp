//LONGEST SUM CONTIGUOUS ARRAY



long long maxSubarraySum(int arr[], int n){
       
       long long maxsofar=INT_MIN;
       long long maxendinghere=0;
       
       for(int i=0;i<n;i++){
           maxendinghere+=arr[i];
           
           if(maxsofar < maxendinghere){
               maxsofar=maxendinghere;
           }
           
           if(maxendinghere < 0){
               maxendinghere=0;
           }
       }
       return maxsofar;
    }