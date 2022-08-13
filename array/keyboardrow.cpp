// Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

// In the American keyboard:

// the first row consists of the characters "qwertyuiop",
// the second row consists of the characters "asdfghjkl", and
// the third row consists of the characters "zxcvbnm".



#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool check(string s,unordered_map<char,int> m){
        for(int i=0;i<s.length();i++){
            if(!m[tolower(s[i])])
                return false;
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        vector<string > ans;
        unordered_map<char,int> m1,m2,m3;
        string s="qwertyuiop";
        for(int i=0;i<s.length();i++){
            m1[s[i]]++;
        }
        s="asdfghjkl";
        for(int i=0;i<s.length();i++){
            m2[s[i]]++;
        }
        s="zxcvbnm";
        for(int i=0;i<s.length();i++){
            m3[s[i]]++;
        }
        
        for(int i=0;i<words.size();i++){
            if(check(words[i],m1))
                ans.push_back(words[i]);
            else if( check(words[i],m2))
                 ans.push_back(words[i]);
            else if(check(words[i],m3)) 
                 ans.push_back(words[i]);
        }
        return ans;
    }
};