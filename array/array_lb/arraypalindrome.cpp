class Solution {
public:
    bool checkpalindrome(int n){
        int temp=n;
        int mul=1;
        int rev=0;
        while(temp!=0){
            int rem=temp%10;
            rev=rev*10+rem;
            temp/=10;
        }
        if(rev==n)
            return true;
        return false;
    } 
    int PalinArray(int a[], int n)
    {
    	for(int i=0;i<n;i++){
    	    if(!checkpalindrome(a[i]))
    	        return false;
    	}
    	return true;
    }
};