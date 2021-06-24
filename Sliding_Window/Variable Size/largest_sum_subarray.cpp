// largest sum subarray (variable size window)
// only apply on positive integers
#include <bits/stdc++.h>
using namespace std;

#define harry                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int Largest_Sum(int arr[], int n, int k)
{
    int i = 0, j = 0;
    int mx = 0, sum = 0;
    while (j < n)
    {
        sum += arr[j];
        if (sum < k)
            j++;
        else if (sum == k)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }
            if (sum == k) // to check whether the sum is k or not
                mx = max(mx, j - i + 1);
            j++;
        }
    }
    return mx;
}
int main()
{
    harry;
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k; // given sum
    cout << Largest_Sum(arr, n, k);
    return 0;
}