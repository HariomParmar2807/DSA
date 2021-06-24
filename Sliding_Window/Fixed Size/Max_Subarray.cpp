#include <bits/stdc++.h>
using namespace std;
#define harry                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
// maximum sum subarray of size k
int Sum_subarray(int arr[], int n, int k)
{
    int start = 0, end = 0;
    int mx_sum = INT_MIN, sum = 0;
    while (end < n)
    {
        sum += arr[end];
        if (end - start + 1 < k)
            end++;
        else if (end - start + 1 == k)
        {
            mx_sum = max(mx_sum, sum);
            //cout << mx_sum << "\n";
            sum -= arr[start];
            start++;
            end++;
        }
    }
    return mx_sum;
}
int main()
{
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    cout << Sum_subarray(arr, n, k);
    return 0;
}