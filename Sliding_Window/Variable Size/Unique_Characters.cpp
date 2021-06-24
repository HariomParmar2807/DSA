// largest subarray of k unique chracters
// variable sliding window
#include <bits/stdc++.h>
using namespace std;

#define ios_base              \
    ::sync_with_stdio(false); \
    cin.tie(NULL)

int Largest_Substring(string str, int k)
{
    int i = 0, j = 0;
    int max_len = 0;
    unordered_map<char, int> um;
    while (j < str.size())
    {
        um[str[j]]++;
        if (um.size() < k)
            j++;
        else if (um.size() == k)
        {
            max_len = max(max_len, j - i + 1);
            j++;
        }
        else
        {
            while (um.size() > k)
            {
                um[str[i]]--;
                if (um[str[i]] == 0)
                    um.erase(str[i]);
                i++;
            }
            j++;
        }
    }
    return max_len;
}
int main()
{
    string str;
    cin >> str;
    int k;
    cin >> k;
    cout << Largest_Substring(str, k);
    return 0;
}