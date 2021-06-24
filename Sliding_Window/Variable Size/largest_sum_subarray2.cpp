// largest sum subarray (variable size window)
// Apply on both positive and negative integers
#include <bits/stdc++.h>
using namespace std;

#define harry                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int Largest_Sum(int arr[], int n, int k)
{
    int i = 0, sum = 0; // one pointer
    int max_len = 0;
    unordered_map<int, int> um;
    while (i < n)
    {
        sum += arr[i];
        if (sum == k) // when subarray starts from index '0'
            max_len = i + 1;
        if (um.find(sum) == um.end())
            um[sum] = i;
        if (um.find(sum - k) != um.end()) // check whether sum - k present in map or not
        {
            if (i - um[sum - k] > max_len)
                max_len = i - um[sum - k];
        }
        ++i;
    }
    return max_len;
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