
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
   
    vector<int> plusOne(vector<int>& v) {
        
        //reverse the vector
        reverse(v.begin(),v.end());
        
        //initialize carry with 1
        int carry=1;
      
        //traverse vector from beginning
        for(int i=0;i<v.size();i++){
            
            //add carry to the numbers
            int sum=v[i]+carry;
            
            v[i]=sum%10;
            
            carry=sum/10;
            
            //if there is no value to add as carry then break
            if(carry==0)
                break;
        }
       
        //if carry is not equal to 0 then push it in the vector
        if(carry != 0)
            v.push_back(carry);
        
        //reverse the vector
        reverse(v.begin(),v.end());

        return v;
    }
};