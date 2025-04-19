#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int beautySum(string s) { // brute force find all substrings, and just calculate the max and min freq using frequency array on alphabets, which will have constant time complexity
            // TC: O(n^2), SC: O(1)
            int n = s.size();
            int totalBeauty = 0;
             
            for (int i = 0; i < n; ++i) { // TC: O(n)
                vector<int> freq(26, 0);
                for (int j = i; j < n; ++j) { // TC: O(n)
                       
                     freq[s[j]-'a']++; // this is the line which is making the difference because at each iteration of j loop the vector is different and that current vector is the substring let's say the first substring is aabcb but first its a-1 in the frequency vector which gives beauty of 0 then a - 2 which also gives 0 , then a - 2 b - 1 which gives 1 and so on, this happens in one loop of j and when combined with i loop it generates all substrings with the method same start and end different.
                        int maxFreq = 0, minFreq = INT_MAX;
                        for (int f : freq) {
                             if (f > 0) {
                                 maxFreq = max(maxFreq, f);
                                 minFreq = min(minFreq, f);
                             }
                        }
             
                        totalBeauty += maxFreq - minFreq;
                    }
                }
             
                 return totalBeauty;
        }

        int beautySum1(string s) { // Brute force
            // TC: O(n^3)
            int n = s.size();
            int totalBeauty = 0;
        
            for (int i = 0; i < n; ++i) {
                for (int j = i; j < n; ++j) {
                    vector<int> freq(26, 0);
                    for (int k = i; k <= j; ++k) {
                        freq[s[k] - 'a']++;
                    }
        
                    int maxFreq = 0, minFreq = INT_MAX;
                    for (int f : freq) {
                        if (f > 0) {
                            maxFreq = max(maxFreq, f);
                            minFreq = min(minFreq, f);
                        }
                    }
        
                    totalBeauty += maxFreq - minFreq;
                }
            }
        
            return totalBeauty;
        }
        
};

int main()
{
  string s;
  cin>>s;
  Solution sol;
  int ans=sol.beautySum(s);
  cout<<ans;
  return 0;
}