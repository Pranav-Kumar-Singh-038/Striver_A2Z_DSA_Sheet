#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> &a, pair<char, int> &b) {
    return a.second > b.second;
}

class Solution {
    public:
    string frequencySort(string s) { // Count the frequency of each character, store it in a vector of pairs, sort the pairs by frequency in descending order, and construct the result string by repeating characters based on their frequency.
        // TC: O(n+n) = O(n), SC: O(n)
        vector<int> freq(128, 0);  //SC: O(1)
    
        for (char ch : s) { // TC: O(n)
            freq[(int)ch]++;
        }
    
        vector<pair<char, int>> freqPairs; // SC: O(1) as in worst case it will push 128 pairs
    
        for (int i = 0; i < 128; i++) {
            if (freq[i] > 0) {
                freqPairs.push_back({(char)i, freq[i]});
            }
        }
    
        sort(freqPairs.begin(), freqPairs.end(), cmp); // TC: O(klogk) = O(128log128) = O(1)
   
    
        string ans; // SC: O(n)
        for (auto &p : freqPairs) { // TC: O(n)
            ans += string(p.second, p.first); // similar to string(3,'a') which gives aaa
        }
    
        return ans;
    }
    
};

int main()
{
  string s;
  cin>>s;
  Solution sol;
  string ans=sol.frequencySort(s);
  cout<<ans;
  return 0;
}