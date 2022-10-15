       vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
           vector <int> ans;
           vector<int> :: iterator it;
           int i=0,j=0,k=0;
           while(i<n1 && j<n2 && k<n3){
               if(a[i]==b[j] && b[j]==c[k]){
                   it=find(ans.begin(),ans.end(),a[i]);
                   if(it==ans.end())
                    ans.push_back(a[i]);
                    i++;
                    j++;
                    k++;
               }
               else if(a[i] < b[j]){
                   i++;
               }
               else if(b[j] < c[k]){
                   j++;
               }
               else
                    k++;
               
           }
           return ans;
        }