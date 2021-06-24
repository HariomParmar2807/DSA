// find first negative integer in every window of size k
#include <bits/stdc++.h>
using namespace std;
#define harry                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
// maximum sum subarray of size k
void first_negative(int arr[], int n, int k)
{
    int i = 0, j = 0; // denote start and end
    queue<int> q;
    while (j < n)
    {
        if (arr[j] < 0)
            q.push(arr[j]);
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            if (q.empty())
                cout << 0 << " ";
            else
                cout << q.front() << " ";
            if (arr[i] == q.front())
                q.pop();
            i++;
            j++;
        }
    }
}
int main()
{
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    first_negative(arr, n, k);
    return 0;
}