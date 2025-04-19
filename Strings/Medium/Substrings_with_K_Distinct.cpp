#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int atMostKDistinct(const std::string& s, int k) { // This function uses a sliding window to count all substrings with at most `k` distinct characters.  It expands the window with `right` and shrinks it with `left` when the distinct character count exceeds `k`, adding valid substring counts at each step.
        // TC: O(2n) = O(n), SC: O(1)
        unordered_map<char, int> myMap; // SC:O(256) // this is store the freqs of all strings
        int left = 0, count = 0, n = s.size();
    
        for (int right = 0; right < n; ++right) { // TC: O(n) // main sliding window
            myMap[s[right]]++; // frequency array
            while (myMap.size() > k) { //when map increases more than k it means we have more than k distinct charecters so we reduce the char at l// TC: O(n), but independently as left will reach n only once
                myMap[s[left]]--;
                if (myMap[s[left]] == 0) { // if the frequency becomes 0 we remove the element so as it is not counted after that
                    myMap.erase(s[left]);
                }
                left++;
            }
    
            count += right - left + 1; // this is the sum of all substrings ending at right which eventually gives sum of all substrings of strings, our general method typically makes strings starting at an index l
        }
    
        return count;
    }
    
    int countSubstr(std::string& s, int k) { // The number of substrings with exactly `k` distinct characters is equal to the number of substrings with **at most** `k` distinct characters minus the number with at most `k - 1` distinct characters.
        // TC: O(2n+2n) = O(4n) = O(n), SC: O(1)
        return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
    }
    
    
};

int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    Solution sol;
    int ans=sol.countSubstr(s,k);
    cout<<ans;
    return 0;
}