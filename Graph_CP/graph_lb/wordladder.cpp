class Solution {
public:
    int ladderLength(string s, string e, vector<string>& wordlist) {
        queue<string> q;
        int wordsize=s.length();
        unordered_set<string> word;
        for(int i=0;i<wordlist.size();i++){
            word.insert(wordlist[i]);
        }
        if(word.find(e) == word.end())
            return 0;
       q.push(s);
        int len=0;
        while(!q.empty()){
            len++;
            int qlen=q.size();
            for(int i=0;i<qlen;i++){
                string s=q.front();
                q.pop();
                
                for(int j=0;j<wordsize;j++){
                    char temp=s[j];
                    for(char ch='a';ch<='z';ch++){
                        s[j]=ch;
                       
                        if(s == e)
                            return len+1;
                        if(word.find(s) == word.end())
                            continue;
                        word.erase(s);
                        q.push(s);
                    }
                    s[j]=temp;
                }
            }
        }
        return 0;
    }
};