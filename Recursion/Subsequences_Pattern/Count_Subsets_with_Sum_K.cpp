#include <bits/stdc++.h>
using namespace std;

int Ways(vector<int> &arr, int k, int currSum, int index) // return 1 if found sum, 0 else, each time, take two cases, wether to include the number or not, do this recursively,
{
    // TC: O(2^n), SC: O(n) // because at each recursive call index increases by 1 and it goes to n max
    if (currSum == k)
    {
        return 1;
    }
    if (currSum > k || index >= arr.size())
    {
        return 0;
    }

    currSum += arr[index];
    int l = Ways(arr, k, currSum, index+1);
    // Not Pick
    currSum -= arr[index];
    int r = Ways(arr, k, currSum, index+1);
    return l + r;
}

int findWays(vector<int> &arr, int k)
{
    int sum = 0;
    int index = 0;
    int ans = Ways(arr, k, sum, index);
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (auto &it : vec)
    {
        cin >> it;
    }
    int ans = findWays(vec, k);
    cout << ans;
    return 0;
}