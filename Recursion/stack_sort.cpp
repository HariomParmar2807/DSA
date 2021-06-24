// delete middle element of stack
#include <bits/stdc++.h>
using namespace std;

#define harry                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
void delete_stack(stack<int> &st)
{
    int mid =
}
int main()
{
    harry;
    int n, val;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        st.push(val);
    }
    delete_stack(st, 0, st.size() - 1);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}