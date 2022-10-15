	long long maxProduct(vector<int> arr, int n) {
	   if(n==1)
	    return arr[0];
	    long long pro=1;
	    long long maxpro=INT_MIN;
	    
	    //traverse left to right
	    for(int i=0;i<n;i++){
	        pro*=arr[i];
	        
	        maxpro=max(maxpro,pro);
	        if(pro == 0)
	            pro=1;
	    }
	    
	    pro=1;
	    //traverse right to left
	    for(int i=n-1;i>=0;i--){
	        pro*=arr[i];
	        maxpro=max(maxpro,pro);
	        if(pro == 0)
	            pro=1;
	    }
	    return maxpro;
	}