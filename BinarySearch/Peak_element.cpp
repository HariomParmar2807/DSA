// find the peak element in array
// this problem is based on binary search on answer concept
// peak element that element who is greater both neighbours
// this is also concept of max element in bitonic arrray
#include <bits/stdc++.h>
using namespace std;

int find_peak(int arr[], int start, int end)
{
  int n = end + 1;
  while (start <= end)
  {
    if (start == end)
      return start;
    int mid = (start + (end - start) / 2);
    if (mid > 0 && mid < n - 1)
    {
      if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        return mid;
      else if (arr[mid - 1] > arr[mid])
        end = mid - 1;
      else
        start = mid + 1;
    }
    else if (mid == 0)
    {
      if (arr[0] > arr[1])
        return 0;
      else
        return 1;
    }
    else // mid==n-1
    {
      if (arr[n - 1] > arr[n - 2])
        return n - 1;
      else
        return n - 2;
    }
  }
}
int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i]; //unsorted array
  cout << find_peak(arr, 0, n - 1);
  return 0;
}