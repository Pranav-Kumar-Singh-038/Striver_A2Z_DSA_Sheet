#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKSumPairs(vector<int> &a, vector<int> &b, int k)
    {
        // sort the arrays, insert the first pair obviously the first in both arrays
        // which are highest into maxheap, mark it as visited, now always push two combinations
        // into maxheap, (i,j+1) and (i+1,j) because only they can be the largest, then pop
        // form maxHeap it will give bigger one, you also push i and j of the value into heap
        // so when you pop you know where to continue from, if you pushed i+1, j, then 
        // next you will push, i+2,j,, i+1,j+1. the heap already has i,j+1. It will give the
        // max of these and you will keep going forward, we track visited for this purpose
        // suppose you went too down one part let's say i+4,j+3. now when you find i+2,j+1 as valid
        // you must check if you had already visited it or not.
        // TC:O(3nlogn)=O(nlogn), SC:O(3n) = O(n)
        int n = a.size();
        // TC:O(2nlogn)
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());

        priority_queue<pair<int, pair<int, int>>> maxHeap; // SC:O(n)
        set<pair<int, int>> visited; // SC:O(n)

        maxHeap.push({a[0] + b[0], {0, 0}}); // TC:O(1)
        visited.insert({0, 0});
 
        vector<int> result; // SC:O(n)

        while (result.size() < k) // TC:O(n)
        {
            auto top = maxHeap.top();
            maxHeap.pop(); // TC:O(logn)

            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;

            result.push_back(sum); 

            // add next element in a if not visited
            if (i + 1 < n && visited.find({i + 1, j}) == visited.end())
            {
                maxHeap.push({a[i + 1] + b[j], {i + 1, j}}); // TC:O(logn)
                visited.insert({i + 1, j});
            }

            // add next element in b if not visited
            if (j + 1 < n && visited.find({i, j + 1}) == visited.end())
            {
                maxHeap.push({a[i] + b[j + 1], {i, j + 1}}); // TC:O(logn)
                visited.insert({i, j + 1});
            }
        }

        return result;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int &it : a)
    {
        cin >> it;
    }
    for (int &it : b)
    {
        cin >> it;
    }
    Solution sol;
    vector<int> ans = sol.topKSumPairs(a, b, k);
    for (int &it : ans)
    {
        cout << it << " ";
    }
}


 /*1. Sort both arrays in descending order. This ensures the largest sums are formed first.
    2. Use a max-heap (priority_queue) to always extract the current maximum sum.
       - Each heap entry stores: (sum, i, j) → representing a[i] + b[j]
    3. Initially push the pair (0, 0), which gives the largest sum (a[0] + b[0]).
    4. Track visited index pairs (i, j) using a set to avoid duplicates.
    5. For each popped pair (i, j), try to push:
        - (i+1, j) → next element in array a
        - (i, j+1) → next element in array b
       Only push if within bounds and not visited.
    6. Repeat until we've collected K sums. */