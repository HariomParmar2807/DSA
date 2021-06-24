// Implement naive solution or brute force solution of pattern matching 
#include<bits/stdc++.h>
using namespace std;

void brute_force(string text,string pat)
{
    int lt = text.length();
    int lp = pat.length();
    int max = lt-lp+1;
    bool flag;
    for(int i=0;i<max;i++)
    {
        flag=true;
        for(int j=0;j<lp && flag==true;j++)
        {
            if(pat[j]!=text[j+i])
              flag=false;
        }
         if(flag)
           cout<<"Starting index of text="<<i+1<<endl;
    }
    
}
int main()
{
    string text,pat;
    cin>>text>>pat;
    brute_force(text,pat);
    return 0;
}
// time complexity is high o(lp*lt)