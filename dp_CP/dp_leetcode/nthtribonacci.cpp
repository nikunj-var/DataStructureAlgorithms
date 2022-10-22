class Solution {
public:
    int tribonacci(int n) {
        int a=0,b=1,c=1;
        int d;
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        int m=n-2; 
        int i=3;
        while(n>=3){
            d=a+b+c;
            a=b;
            b=c;
            c=d;
            n--;
        }
        return d;
    }
};nth