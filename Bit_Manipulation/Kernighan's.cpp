// count set bits in an integer(kernighan's algo)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,count=0;cin>>n;
    int rsb;
    while(n!=0)
    {
      ++count;
      rsb = n&(-n);
      n = n-rsb;
    }
    cout<<count;
    return 0;
}