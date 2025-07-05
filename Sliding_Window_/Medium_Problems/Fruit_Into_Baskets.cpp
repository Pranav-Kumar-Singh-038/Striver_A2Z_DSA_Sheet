#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)// make a hashmap, and store the freq of fruits in it, if the hash map size
    // increases more than 2 than keep moving the head until its freq is 0 then erase from hashmap, other wise
    // also remember to store maxFruit in a separate variable, as you have to give max, not just return totalfruits(which i once did btw).
    {
        // TC: O(2n), SC:O(1)
        unordered_map<int, int> hashMap; // SC:O (n), but it will be 3 as we are storing max 3 fruits at a time
        int n = fruits.size();
        int head = 0, tail = 0;
        int totalFruit = 0;
        int basketSize;
        int maxFruit=0;
        while (tail != n) // TC:O(n)
        {
            int tailElement = fruits[tail];
            hashMap[tailElement]++;
            basketSize = hashMap.size();
            while (basketSize > 2) // TC:O(n)
            {
                int headElement = fruits[head];
                hashMap[headElement]--;
                if (hashMap[headElement] == 0)
                {
                    hashMap.erase(headElement);
                    basketSize--;
                }
                head++;
            }
            totalFruit = tail - head + 1;
            maxFruit=max(maxFruit,totalFruit);
            tail++;
        }
        return maxFruit;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> fruits(n);
    for (int &it : fruits)
    {
        cin >> it;
    }

    Solution sol;
    int ans = sol.totalFruit(fruits);
    cout << ans;
    return 0;
}