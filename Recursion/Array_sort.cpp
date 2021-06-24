// Sort an array using recursion
#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &arr, int temp)
{
    if (arr.size() == 0 || arr[arr.size() - 1] <= temp)
    {
        arr.push_back(temp);
        return;
    }
    int val = arr[arr.size() - 1];
    arr.pop_back();
    // now insert the temp value
    insert(arr, temp);
    // push the popped value
    arr.push_back(val);
}
void sort_arr(vector<int> &arr)
{
    if (arr.size() == 1)
        return;
    // remove element from last
    int val = arr[arr.size() - 1];
    arr.pop_back();
    sort_arr(arr); // hypothesis
    // Insert the removed element
    insert(arr, val);
}
int main()
{
    int n, val;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr.push_back(val);
    }
    sort_arr(arr);
    for (auto it : arr)
        cout << it << " ";
    return 0;
}