// hariom parmr
#include <bits/stdc++.h>
using namespace std;
#define harry                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
// to find the longest pallindrome subsequence using dp

int lps(string str, int start, int end)
{
    // cases
    if (start == end)
        return 1;
    // two charcter and both same
    if (str[start] == str[end] && end == start + 1)
        return 2;
    // first and last character of string is same
    if (str[start] == str[end])
        return lps(str, start + 1, end - 1) + 2;
    else
        return max(lps(str, start + 1, end), lps(str, start, end - 1));
}
int main()
{
    harry;
    string str;
    getline(cin, str);
    cout << lps(str, 0, str.length() - 1);
    return 0;
}
// hariom parmar is a student of iiit kota mnit campus jaipur
// computer science branch.