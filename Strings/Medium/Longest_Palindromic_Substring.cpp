#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool checkForPalindrome(string sub)
        {
            int l=0,r=sub.size()-1;
            while(l<=r)
            {
                if(sub[l]!=sub[r])
                {
                    return false;
                }
                l++;
                r--;
            }
            return true;
        }

        string longestPalindrome(string s) { // same as below slightly more optimal
         // TC: O(2n^2), SC: O(1)
            int n = s.size();
            if (n == 0) return "";  
            if (n == 1) return s;  
            
            int start = 0, maxLength = 1;  
            
            for (int i = 0; i < n; i++) {
                // Odd-length palindrome (single center)
                int l1 = i, r1 = i;
                while (l1 >= 0 && r1 < n && s[l1] == s[r1]) {
                    if (r1 - l1 + 1 > maxLength) {
                        maxLength = r1 - l1 + 1;
                        start = l1;  // Update start index of the palindrome
                    }
                    l1--;
                    r1++;
                }
        
                // Even-length palindrome (center between two characters)
                int l2 = i, r2 = i + 1;
                while (l2 >= 0 && r2 < n && s[l2] == s[r2]) {
                    if (r2 - l2 + 1 > maxLength) {
                        maxLength = r2 - l2 + 1;
                        start = l2;  // Update start index of the palindrome
                    }
                    l2--;
                    r2++;
                }
            }
            
            return s.substr(start, maxLength);
        }
        

        string longestPalindrome2(string s) { // we treat all indexes as centers of palindrome substring, we expand from there until a palindrome is valid, store the max substring found as such. We handle two cases for even and odd strings
            // TC: O(n(n+n))= O(2n^2)= O(n^2), SC: O(n)
            int n=s.size();
            int maxLength=0;
            string maxSubstr; // SC: O(n)
            for(int i=0;i<n;i++) // TC: O(n)
            {
                int l1=i;
                int r1=i;
                while(l1>=0 && r1<n && s[l1]==s[r1]) // TC: O(n)
                {
                    if (r1 - l1 + 1 > maxLength) {
                        maxLength = r1 - l1 + 1;
                        maxSubstr = s.substr(l1, r1 - l1 + 1);
                    }
                  l1--;
                  r1++;
                }

                int l2=i;
                int r2=i+1;
                while(l2>=0 && r2<n && s[l2]==s[r2]) // TC: O(n)
                {
                    if (r2 - l2 + 1 > maxLength) {
                        maxLength = r2 - l2 + 1;
                        maxSubstr = s.substr(l2, r2 - l2 + 1); // String function to create substring
                    }
                  l2--;
                  r2++;
                }
            }
            return maxSubstr;
        }

        string longestPalindrome1(string s) { // Brute Force
            // TC: O(n^3)
            string sub;
            string ans;
            int max=0;
            bool isPalindrome=false;
            for(int i=0;i<s.size();i++) // TC: O(n)
            {
                for(int j=i;j<s.size();j++) // TC: O(n)
                {
                    sub = s.substr(i, j - i + 1);
                    // cout<<sub<<endl;
                    isPalindrome=checkForPalindrome(sub); // TC: O(n)
                    if(isPalindrome)
                    {
                    //    cout<<sub<<endl;
                      if(sub.size()>max)
                      {
                        ans=sub;
                        max=sub.size();
                      }
                    }
                }
            }
            return ans;
            
        }
};

int main()
{
    string s;
    cin>>s;
    Solution sol;
    string ans=sol.longestPalindrome(s);
    cout<<ans;
    return 0;
}