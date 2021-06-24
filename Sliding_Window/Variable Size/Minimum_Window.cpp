// print Minimum substring length that contain other string
#include <bits/stdc++.h>
using namespace std;

string Minimum_Substring(string txt, string pat)
{
    int i = 0, j = 0;
    int min_len = INT_MAX;
    unordered_map<char, int> um;
    for (int i = 0; i < pat.length(); i++)
        um[pat[i]]++;
    int count = um.size();
    int start = 0;
    while (j < txt.length())
    {
        // if (um.find(txt[j]) != um.end())
        // {
        um[txt[j]]--;
        if (um[txt[j]] == 0)
            --count;
        //}
        if (count == 0)
        {
            while (count == 0)
            {
                if (min_len > j - i + 1)
                {
                    min_len = j - i + 1;
                    start = i;
                }
                um[txt[i]]++;
                if (um[txt[i]] > 0)
                    ++count;
                //}
                i++;
            }
        }
        j++;
    }
    if (min_len != INT_MAX)
        return txt.substr(start, min_len);
    else
        return "-1";
}
int main()
{
    string txt, pat;
    getline(cin, txt);
    cin >> pat;
    cout << Minimum_Substring(txt, pat);
    return 0;
}