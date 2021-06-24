// generate all paranthesis of given length
#include <bits/stdc++.h>
using namespace std;

void generate_paranthesis(int n, string curr, int open, int close)
{
    if (close == n)
    {
        cout << curr << " ";
        return;
    }
    else
    {
        if (open > close)
            generate_paranthesis(n, curr + ')', open, close + 1);
        if (open < n)
            generate_paranthesis(n, curr + '(', open + 1, close);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string str;
    generate_paranthesis(n, "", 0, 0);
    return 0;
}