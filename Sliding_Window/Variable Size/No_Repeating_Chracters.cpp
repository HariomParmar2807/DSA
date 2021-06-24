// pring substring and largest substring length with no repeating chracters(all unique chracters)
// variable sliding window
#include <bits/stdc++.h>
using namespace std;

#define ios_base              \
    ::sync_with_stdio(false); \
    cin.tie(NULL)

void Largest_Substring(string str)
{
    int i = 0, j = 0;
    int max_len = 0;
    unordered_map<char, int> um;
    int start, end;
    while (j < str.size())
    {
        um[str[j]]++;
        if (um.size() == j - i + 1) // if all unique characters
        {
            if (max_len < j - i + 1)
            {
                max_len = j - i + 1;
                start = i;
                end = j;
            }
            j++;
        }
        else if (um.size() < j - i + 1) // if window has some repeating characters
        {
            while (um.size() < j - i + 1)
            {
                um[str[i]]--;
                if (um[str[i]] == 0)
                    um.erase(str[i]);
                i++;
            }
            j++;
        }
        // else -> size of map cannot greater sliding window
    }
    cout << max_len << "\n";
    for (int i = start; i <= end; i++)
        cout << str[i];
}
int main()
{
    string str;
    cin >> str;
    Largest_Substring(str);
    return 0;
}