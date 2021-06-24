// How many times sorted array is rotated=index of min element in array
#include <bits/stdc++.h>
using namespace std;

int count_rotation(int arr[], int n)
{
  if (arr[0] < arr[n - 1])
    return 0;
  int start = 0, end = n - 1;
  int ans = -1;
  while (start <= end)
  {
    if (arr[start] < arr[end])
      return start;
    int mid = (start + (end - start) / 2);
    int next = (mid + 1) % n;
    int prev = (mid + n - 1) % n;
    if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
    {
      ans = mid;
      end = mid - 1;
    }
    else if (arr[start] < arr[mid])
      start = mid + 1;
    else if (arr[mid] < arr[end])
      end = mid - 1;
    else
      start++;
  }
  return ans;
}
int Binary_search(int arr[], int start, int end, int x)
{
  while (start <= end)
  {
    int mid = (start + (end - start) / 2);
    if (arr[mid] == x)
      return mid;
    else if (arr[mid] < x)
      start = mid + 1;
    else
      end = mid - 1;
  }
  return -1;
}
int main()
{
  int n, x;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  //cout << "Required element=";
  //cin >> x;
  int min_index = count_rotation(arr, n);
  cout << min_index;
  /*if (x > arr[0])
    cout << Binary_search(arr, 0, min_index - 1, x);
  else
    cout << Binary_search(arr, min_index, n - 1, x);
 */
  return 0;
}