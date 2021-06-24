// Implement z-algoritham to find pattern in text in liner time
// o(m+n) time complexity
#include<bits/stdc++.h>
using namespace std;
// find z array in linear time 
void Calculate_zvalue(string str,int z[],int l)
{
    z[0]=0;
    int i=1;
    int L=0,R=0;
    while(i<l)
    {
       if(i>R){
          L=R=i;
          while(R<l && str[R]==str[R-L])
             R++;
          z[i]=R-L;
        R--;}
       else  // else function fill the zbox array a/c to previous zbox array
       {
           int j=i-L;
           if(z[j]<R-i+1)
            z[i]=z[j];
           else
           {
               L=i;
              while(R<l && str[R]==str[R-L])
                R++;
              z[i]=R-L;
             R--;   
           }
            
       }
    i++;       
    }
}
void find_pattern(string txt,string pat)
{
    string str="";
    str = pat+"$"+txt;
    int l = str.length();
    int z[l];
    Calculate_zvalue(str,z,l); 
    for(int i=0;i<l;i++)
    {
        if(z[i]==pat.length())
          cout<<"pattern found at index "<<i-pat.length()<<endl;
    }
}
int main()
{
    string txt,pat;cin>>txt>>pat;
    find_pattern(txt,pat);
    return 0;
}