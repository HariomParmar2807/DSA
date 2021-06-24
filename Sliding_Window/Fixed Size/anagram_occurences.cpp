// occurences of anagram in string by sliding window
#include <bits/stdc++.h>
using namespace std;

#define ios_base              \
    ::sync_with_stdio(false); \
    cin.tie(NULL);

int count_anagrams(string txt, string pat)
{
    int i = 0, j = 0;
    string str = "";
    int count = 0;
    while (j < txt.length())
    {
        str += txt[j];
        if (j - i + 1 < pat.length())
            j++;
        else if (j - i + 1 == pat.length())
        {
            string s = str;
            sort(pat.begin(), pat.end());
            sort(s.begin(), s.end());
            if (pat == s)
                count++;
            str.erase(str.begin());
            i++;
            j++;
        }
    }
    return count;
}
int main()
{
    string txt, pat;
    cin >> txt >> pat;
    cout << count_anagrams(txt, pat);
}