#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k) // make a frequency array, traverse the string, store the 
    // current max frequency, this is to determine what is number of max freq in a substring, and replacements
    // would be (end-start+1)-maxFreq, while replacements>k, keep moving the head, and updatin the head frequency
    // also maxFreq as to may be the current start was the max freq, store the maxLength found and return it.
    {
        // TC:O(2n), SC:O(1)
       int n=s.size();
       int start=0,end=0;
       int maxFreq=0;
       vector<int> freq(26,0); // SC:O(1)
       int replacements;
       int maxLength=0;
       while(end!=n) // TC:O(n)
       {
        int letter=s[end];
        freq[letter-'A']++;
        maxFreq=max(maxFreq,freq[letter-'A']);
        replacements=(end-start+1)-maxFreq;
        while(replacements>k) // TC:O(n)
        {
            freq[s[start]-'A']--;
            maxFreq=max(maxFreq,freq[s[start]-'A']);
            start++;
            replacements=(end-start+1)-maxFreq;
        }
        maxLength=max(maxLength,end-start+1);
        end++;
       }
       return maxLength;
    }
};

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    Solution sol;
    int ans = sol.characterReplacement(s, k);
    cout << ans;
    return 0;
}