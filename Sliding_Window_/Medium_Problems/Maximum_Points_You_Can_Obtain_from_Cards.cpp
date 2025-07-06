#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k) // Instead of making a max window of cards from beginning and
    // end, we simply make a continuous window of size n-k in the array,but rather than having max score
    // we find the window with min size, and subtract this size from the total array sum, since to take 
    // max cards we should avoid the window of minimum score.
    {
        // TC:O(3n), SC:O(1)
        int n = cardPoints.size();
        int windowSize = n - k;
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0); // TC:O(n)

        if (windowSize == 0)
        {
            return totalSum;
        }

        int currentSum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0); // TC:O(n)
        int minSubarraySum = currentSum;
        int left = 0;
        int right = windowSize - 1;
        while (right != n) // TC:O(n)
        {
            minSubarraySum = min(minSubarraySum, currentSum);
            currentSum -= cardPoints[left];
            left++;
            right++;
            if (right < n)
            {
                currentSum += cardPoints[right];
            }
        }

        return totalSum - minSubarraySum;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> cardPoints(n);
    for (int &it : cardPoints)
    {
        cin >> it;
    }

    Solution sol;
    int ans = sol.maxScore(cardPoints, k);
    cout << ans;
    return 0;
}