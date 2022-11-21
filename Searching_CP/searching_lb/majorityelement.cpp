    //APPROACH1

    class Solution{    
    public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int n)
    {   
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            if(m[arr[i]] > n/2)
                return arr[i];
        }
       return -1;
        
    }
};

    //MOORE VOTE ALGORITHM
    int majorityElement(int arr[], int n)
    {   
        int count=0,element=0;
        for(int i=0;i<n;i++){
            if(count == 0){
                element=arr[i];
            }
            
            if(element == arr[i])
                count++;
            else
                count--;
        }
        count=0;
        for(int i=0;i<n;i++){
            if(arr[i] == element)
                count++;
        }
        
        if(count > n/2)
            return element;
        return -1;
    }