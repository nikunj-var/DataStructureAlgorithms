class Solution
{
    public:
    struct trienode{
        int count;
        bool isterminal;
        trienode* children[26];
        trienode(){
            count=0;
            isterminal=false;
            for(int i=0;i<26;i++)
                children[i]=NULL;
        }
    };
    void insert(trienode*& root,string s){
        trienode* curr=root;
        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            if(curr->children[index] == NULL){
                curr->children[index]=new trienode();
            }
            //sab elements kii frequency increase krte jao taki pata chale kitni bar call hui hai
            curr->children[index]->count++;
            curr=curr->children[index];
        }
        curr->isterminal=true;
        curr->count++;
    }
    void search(trienode* root,string s,vector<string>& ans){
        trienode* curr=root;
        
        //empty string banai
        string temp="";
        //string ki length tak loop chalaya
        for(int i=0;i<s.length();i++){
            //index find
            int index=s[i]-'a';

            //agr us element ki frequency 1 hai to insert kr do string ans me or return
            if(curr -> children[index]->count == 1){
                temp+=s[i];
                ans.push_back(temp);
                return;
            }
            //temp me add kro or curr ko niche traverse karao
            temp+=s[i];
            curr=curr->children[index];
        }
        if(curr->isterminal){
            ans.push_back(temp);
            return;
        }
    }
    void findprefexes(string arr[],int n,vector<string>& ans){
        //root banai  trienode type ki
        trienode* root=new trienode();
        
        //sare words insert kr diye trie me
        for(int i=0;i<n;i++){
            insert(root,arr[i]);
        }
        
        //search kiye words
        for(int i=0;i<n;i++){
            search(root,arr[i],ans);
        }
    }
    vector<string> findPrefixes(string arr[], int n)
    {   //ans string create karo
        vector<string > ans;
        
        //find karo prefexes
        findprefexes(arr,n,ans);
        return ans;
    }
    
};