// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

void printSubsequence(string input,string output,int index){
    if(index == input.length()){
        cout<<output<<" ";
        return;
    }
    printSubsequence(input,output+input[index],index+1);
    printSubsequence(input,output,index+1);
}

// Driver code
int main()
{
    // output is set to null before passing in as a
    // parameter
    string output = "";
    string input = "abcd";
 
    printSubsequence(input, output,0);
 
    return 0;
}