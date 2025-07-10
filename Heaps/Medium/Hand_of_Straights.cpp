#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        // First check if hand is divisible by groupSize, make a frequency map, we use this
        // to keep track of what is multiple times (duplicates), push every unique element
        // into the minHeap, as we only need the unique element, they will be contigious,
        // adding duplicates will complicate it, for every minheap.top(), move groupSize steps 
        // ahead and check if every one is available in the hashmap, if yes it was possible
        // if the current top has frequency =0, then pop it, do it for every element

        //  Overall, each card appears once in a group, and each heap pop occurs at most once per key.
        //  So total groupings = n / k, and total operations per group = k → O(n) total
        // TC:O(n+nlogn+n+n)=O(nlogn), SC:O(2n) = O(n)
        if (hand.size() % groupSize != 0)
        {
            return false;
        }

        unordered_map<int, int> freq; // SC:O(n)
        for (int card : hand)         // TC:O(n)
        {
            freq[card]++;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap; // SC:O(n)
        for (auto &[num, count] : freq)                         // TC:O(n)
        {
            minHeap.push(num); // TC:O(logn)
        }

        while (!minHeap.empty()) // TC:O(n)
        {
            int start = minHeap.top();
            for (int i = 0; i < groupSize; ++i) // TC:O(groupSize)
            {
                int curr = start + i;
                if (freq[curr] == 0)
                {
                    return false;
                }
                freq[curr]--;
                if (freq[curr] == 0 && curr == minHeap.top())
                {
                    minHeap.pop(); // TC:O(n)
                }
            }
        }

        return true;
    }
};

int main()
{
    int n, groupSize;
    cin >> n >> groupSize;
    vector<int> hand(n);
    for (int &it : hand)
    {
        cin >> it;
    }
    Solution sol;
    bool ans = sol.isNStraightHand(hand, groupSize);
    cout << ans;
    return 0;
}