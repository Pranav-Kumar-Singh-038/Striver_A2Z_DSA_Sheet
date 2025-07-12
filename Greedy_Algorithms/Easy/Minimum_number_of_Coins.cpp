#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minPartition(int N)
    {
        // loop through the denominations, for each denomination if the coin is smaller or equal to required
        // keep pushing it until not so.
        // cleaner
        vector<int> denominations = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        vector<int> change;

        for (int coin : denominations)
        {
            while (N >= coin)
            {
                change.push_back(coin);
                N -= coin;
            }
        }
        return change;
    }

    vector<int> minPartition1(int N)
    {
        // keep adding the coins until change left to pay, use while loop, as you have to
        // add one coin multiple times, pretty much it.
        // TC:O(n), SC:O(n)
        vector<int> denominations = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        vector<int> change; // SC:O(N)
        int i = 0;
        int coin = denominations[i];
        int changeLeft = N;
        while (coin > N) // TC:O(N), total at worst
        {
            i++;
            coin = denominations[i];
        }
        while (i < 10)
        {
            coin = denominations[i];
            if (coin <= changeLeft)
            {
                change.push_back(coin);
                changeLeft -= coin;
            }
            else
            {
                i++;
            }
        }
        return change;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    vector<int> ans = sol.minPartition(n);
    for (int &it : ans)
    {
        cout << it << " ";
    }
}