// //print number from  1 to n

// #include<iostream>
// using namespace std;

// void print(int n){
//     if(n == 0)
//         return;

//     print(n-1);
//     cout<<n<<endl;    
// }

// int main(){
//     int n;
//     cout<<"enter n";
//     cin>>n;
//     print(n);
// }

// //print sum of n natural numbers


// #include<iostream>
// using namespace std;

// int sum(int n,int ans){
//     if(ans == n+1)
//         return 0;

//     return ans+sum(n,ans+1);  
// }

// int main(){
//     int n;
//     cout<<"enter n";
//     cin>>n;
//     cout << sum(n,1);
// }

// //factorial of a number

// #include<iostream>
// using namespace std;

// int factorial(int n){
//     if(n==0 || n==1)
//         return 1;
//     return n*factorial(n-1);    
// }

// int main(){
//     int n;
//     cout<<"enter n";
//     cin>>n;
//     cout<<factorial(n);
// }

// //print fibonacci nth term

// #include<iostream>
// using namespace std;

// int fibonacci(int n){
//     if(n==0 || n==1)
//         return n;
//     return   fibonacci(n-1) + fibonacci(n-2);
// }

// int main(){
//     int n;
//     cout<<"enter n";
//     cin>>n;
//     cout<<fibonacci(n);
// }

// //print x^n 

// #include<iostream>
// using namespace std;

// int multiply(int x,int n){
//    if(n==0)
//     return 1;

//    if(x==0)
//     return 0; 

//     //if n is even
//     if(n%2==0){
//         return multiply(x,n/2) * multiply(x,n/2);
//     }
//     //if n is odd
//     if(n%2 == 1)
//         return multiply(x,n/2) * multiply(x,n/2) * x;
// }

// int main(){
//     int n,x;
//     cout<<"enter n";
//     cin>>n;
//     cout<<"enter x";
//     cin>>x;
//     cout<<multiply(x,n);
// }

// //approach2- print x^n
// #include<iostream>
// using namespace std;

// int multiply(int x,int n){
//    if(n==0)
//     return 1;

//    if(x==0)
//     return 0; 

//     //if n is even
//     if(n%2==0){
//         return multiply(x,n/2) * multiply(x,n/2);
//     }
//     //if n is odd
//     if(n%2 == 1)
//         return multiply(x,n/2) * multiply(x,n/2) * x;
// }

// int main(){
//     int n,x;
//     cout<<"enter n";
//     cin>>n;
//     cout<<"enter x";
//     cin>>x;
//     cout<<multiply(x,n);
// }

// //tower of hanoi
// #include<iostream>
// using namespace std;

// void towerofhanoi(int n,string s,string h,string d){
//     if(n==1){
//         cout<<"transfer disc from "<<s<<" to "<<d<<endl;
//         return;
//     }
//     towerofhanoi(n-1,s,d,h);
//     cout<<"transfer disc from "<<s<<" to "<<d<<endl;
//     towerofhanoi(n-1,h,s,d);
// }
// int main(){
//     int n;
//     cout<<"enter n";
//     cin>>n;
   
//     towerofhanoi(n,"S","H","D");
// }

// //reverse a string

// #include<iostream>
// #include<string>
// using namespace std;
 
// void reverse(string s,int n){
//     if(n < 0)
//         return;
//     cout<<s[n];    
//     reverse(s,n-1);
    
// }
//  int main(){
//     string s;
//     cout<<"enter string";
//     cin>>s;
//     int n=s.length();
//     cout<<"entered string is "<<s<<endl;
//     cout<<"reversed string is ";
//     reverse(s,n-1);
//  }

// //find first and last occurences of an element in string

// #include<iostream>
// #include<string>
// using namespace std;
 
// static int l=-1;
// static int f=-1;

// void find(string s,int i,char target){
//     if(i == s.length()){
//         cout<<"first and last occurences are "<<f<<" "<<l;
//          return;
//     }
       
//     if(s[i]==target){
//         if(f == -1)
//             f=i;
//         else if(l==-1 || l < i)
//             l=i;    
//     }
//     find(s,i+1,target);
// }
//  int main(){
//     string s;
//     char target;
//     cout<<"enter string";
//     cin>>s;
//     cout<<"enter element which you want to find ";
//     cin>>target;
   
//     find(s,0,target);
    
//  }

// //check array is strictly increasing or not

// #include<iostream>
// #include<string>
// using namespace std;

// bool checkarray(int arr[],int n,int i){
//     if(i==n-2){
//         return (arr[i] < arr[i+1]);
//     }

//     if(arr[i] > arr[i+1])
//         return false;

//     return checkarray(arr,n,i+1);    
// }
// int main(){
//     int n;
//     cout<<"enter n";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     cout<<checkarray(arr,n,0);

// }

// //move all x to the end of the string 

// #include<iostream>
// #include<string>
// using namespace std;

// void movex(string s,int &idx,int& count,int &i,string ns){
//     if(idx==s.length()){
//         for(int k=0;k<count;k++)
//             ns+='x';
//         cout<<endl<<ns ;   
//         return;
//     }
//     char c=s[idx++];
//     if(c=='x')
//         count++;
//     else
//         ns+=c;
//     movex(s,idx,count,i,ns);        
// }

// int main(){
//    string s;
//    s="axbcxxd";
//    string newstr="";
//    int i=0,count=0,idx=0;
//    movex(s,idx,count,i,newstr);
// }

// //remove duplicate in a string


// #include<iostream>
// #include<unordered_map>
// #include<string>
// using namespace std;

// void removeduplicate(string s,int i,unordered_map<char,int>& m,string ns){
//     if(i==s.length()){
//         cout<<ns;
//         return;
//     }
//     if(!m[s[i]]){
//         m[s[i]]++;
//         ns+=s[i];
//     }     
//     removeduplicate(s,i+1,m,ns);
// }

// int main(){
//    string s;
//    cout<<"enter string";
//    cin>>s;
//    string newstr="";
//    unordered_map<char,int> m;
//    int i=0,count=0,idx=0;
//    removeduplicate(s,idx,m,newstr);
// }


// #include<iostream>
// #include<unordered_map>
// #include<string>
// using namespace std;

// void removeduplicate(string s,int i,unordered_map<char,int>& m,string ns){
//     if(i==s.length()){
//         cout<<ns;
//         return;
//     }
//     if(!m[s[i]]){
//         m[s[i]]++;
//         ns+=s[i];
//     }     
//     removeduplicate(s,i+1,m,ns);
// }

// int main(){
//    string s;
//    cout<<"enter string";
//    cin>>s;
//    string newstr="";
//    unordered_map<char,int> m;
//    int i=0,count=0,idx=0;
//    removeduplicate(s,idx,m,newstr);
// }

// //REVERSE A STRING

// #include<string>
// #include<iostream>
// using namespace std;

// int main(){
//    string s;
//    cout<<"enter string";
//    cin>>s;
//    int i=0;
//    int j=s.length()-1;
//    while(i<j){
//     swap(s[i],s[j]);
//     i++;
//     j--;
//    }
//    cout<<s;
// }

