// maximum in all subarray
#include <bits/stdc++.h>
using namespace std;
#define harry                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
// maximum sum subarray of size k
int Max_subarray(int arr[], int n, int k)
{
    int i = 0, j = 0;
    priority_queue<int> pq;
    while (j < n)
    {
        pq.push(arr[j]);
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            cout << pq.top() << " ";
            if (arr[i] == pq.top())
                pq.pop();
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
    Max_subarray(arr, n, k);
    return 0;
}