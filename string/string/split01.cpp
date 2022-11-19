//approach1
class Solution {
public:
    int maxSubStr(string str){
        int n=str.length();
        int count0 = 0, count1 = 0;
 
    // To store the count of maximum
    // substrings str can be divided into
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            count0++;
        }
        else {
            count1++;
        }
        if (count0 == count1) {
            cnt++;
        }
    }
 
    // It is not possible to
    // split the string
    if (count0!=count1) {
        return -1;
    }
 
    return cnt;
    }
};

//approach2
class Solution {
public:
    int maxSubStr(string str){
        if(str.length()%2 != 0)
            return -1;
        int ans=0;
        int zero=0;
        int one=0;
        for(int i=0;i<str.length();i++){
           if(str[i] == '0'){
               zero++;
           }
           if(str[i] == '1'){
               one++;
           }
           if(zero == one){
               ans++;
               zero=0;
               one=0;
           }
        }
        
        return (zero==0&&one==0)?ans:-1;
    }
};