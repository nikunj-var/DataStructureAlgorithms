
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

    long long int merge(long long arr[],long long temp[],int left,int mid,int right){
        int i,j,k;
        i=left;
        k=left;
        j=mid;
        
       long long int invcount=0;
        while(i <= mid-1 && j<=right){
            if(arr[i] <= arr[j]){
                temp[k++]=arr[i++];
            }
            else{
                temp[k++]=arr[j++];
                invcount+=(mid-i);
            }
        }
         while(i <= mid-1 ){
                temp[k++]=arr[i++];
        
        }
         while( j<=right){
                temp[k++]=arr[j++];
        }
        
        for(int i=left;i<=right;i++)
            arr[i]=temp[i];
            
        return invcount;    
    }
    
    long long int mergesort(long long arr[],long long temp[],int left,int right){
        int mid;
        long long int invcount=0;
        if(left < right){
            int mid=left + (right-left)/2;
            invcount+=mergesort(arr,temp,left,mid);
            invcount+=mergesort(arr,temp,mid+1,right);
            invcount+=merge(arr,temp,left,mid+1,right);
        }
        return invcount;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        long long temp[n];
        long long int ans=mergesort(arr,temp,0,n-1);
        return ans;   
    }

