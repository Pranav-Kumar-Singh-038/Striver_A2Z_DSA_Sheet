#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printHeap(priority_queue<int, vector<int>, greater<int>> pq)
    {
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
    }

    // Since each element is at max k position away from its ideal position
    // If we compare all element within that k window, the smallest one must be the
    // starting one, then we repeat for entire array
    // 6,5,3,2 k=3 this means withing this window the smallest must be at index=0;
    // we simply push all to priority queue, 2 will be at top, which we will insert at index=0
    // then we pop it, insert the next one, and in that window the smallest must be at
    // top in pq, index=2 and so on.
    void nearlySorted(vector<int> &arr, int k)
    {
        // TC:O(k+(n-k)(2logk) +klogk) = O(k+2nlogk-2klogk+klogk) = O(k+2nlogk-klogk) = O(nlogk), SC:O(k)
        priority_queue<int, vector<int>, greater<int>> pq; // SC:O(k)
        int i = 0;
        int temp = k;
        while (temp >= 0) // TC:O(k)
        {
            pq.push(arr[i]);
            i++;
            temp--;
        }
        int j = 0;
        for (int i = k + 1; i < arr.size(); i++) // TC:O(n-k)
        {
            arr[j] = pq.top();
            pq.pop(); // TC:O(logk)
            pq.push(arr[i]); // TC:O(logk)
            j++;
        }

        while (!pq.empty()) // TC:O(k)
        {
            arr[j] = pq.top(); 
            pq.pop(); // TC:O(logk)
            j++;
        }
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }

    Solution sol;
    sol.nearlySorted(arr, k);
    for (auto &it : arr)
    {
        cout << it << " ";
    }
}