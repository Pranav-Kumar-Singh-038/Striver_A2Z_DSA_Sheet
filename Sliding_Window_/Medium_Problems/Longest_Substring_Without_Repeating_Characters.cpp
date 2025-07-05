#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)// Traverse the string, store the freq of each charecter, if it exceeds 1, keep moving the head
    // until the frequency restores back to one, then store the size of max string size formed,
    {
        // TC: O(2n), SC:O(n)
        if(s.size()==0)
        {
            return 0;
        }
        int n = s.size();
        unordered_map<char, int> hashMap; // SC:O (n) This can be optimized if hashmap if all ascii charecters
        int tail = 0, head = 0;
        int maxLength = 0;
        while (tail != n ) // TC:O(n)
        {
            hashMap[s[tail]]++;
            while (hashMap[s[tail]] != 1)// TC:O (n)
            {
                hashMap[s[head]]--;
                head++;
            }
            maxLength = max(maxLength, tail - head + 1);
            tail++;
        }
        return maxLength;
    } 
};

int main()
{
    string s;
    getline(cin, s);    
    Solution sol;
    int ans = sol.lengthOfLongestSubstring(s);
    cout << ans;
    return 0;
}
