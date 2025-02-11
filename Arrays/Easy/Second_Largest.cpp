#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getSecondLargest(vector<int> &arr) // remember to return -1 if secondLargest remains -1 till end
    {
        // TC: O(n), SC: O(1)
        if (arr.size() < 2)
            return -1; 

        int largest = INT_MIN, secondLargest = INT_MIN;

        for (int x : arr)
        {
            if (x > largest)
            {
                secondLargest = largest; 
                largest = x;            
            }
            else if (x > secondLargest && x < largest)
            {
                secondLargest = x;
            }
        }

        return (secondLargest == INT_MIN) ? -1 : secondLargest;
    }

    int getSecondLargest2(vector<int> &arr) // using two passes to find largest then second
    {
        // TC: O(2n), SC:O(1)
        int largest = arr[0];
        for (int x : arr)
        {
            if (x > largest)
            {
                largest = x;
            }
        }
        int secondLargest = -1;
        for (int x : arr)
        {
            if (x > secondLargest && x < largest)
            {
                secondLargest = x;
            }
        }
        return secondLargest;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &x : vec)
    {
        cin >> x;
    }
    Solution sol;
    int ans = sol.getSecondLargest(vec);
    cout << ans;
}
