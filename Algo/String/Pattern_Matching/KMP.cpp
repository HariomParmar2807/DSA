// Implement kmp algoritham to find pattern in text
#include<bits/stdc++.h>
using namespace std;
void Calculate_lps(string pat,int m,int *lps)
{
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
           if(len!=0)
            len=lps[len-1];
           else
           {
               lps[i]=0;
               i++;
           }
       }
    }    
   
}
void Find_pattern(string text,string pat)
{
    int n = text.length();
    int m = pat.length();

    int lps[m];
    
    Calculate_lps(pat,m,lps);
    int i=0,j=0;
    while(i<n)
    {
        if(text[i]==pat[j])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            cout<<"Pattern found at index="<<i-j+1<<endl;
            j=lps[j-1];
        }
        else if(i<n && text[i]!=pat[j])
        {
            if(j!=0)
              j=lps[j-1];
            else
              i++;              
        }
    }
}

int main()
{
    string text,pat;
    cin>>text>>pat;
    Find_pattern(text,pat);
    return 0;
}