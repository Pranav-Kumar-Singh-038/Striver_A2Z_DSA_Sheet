#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isIsomorphicOptimal(string s, string t) {
        unordered_map<char, int> charIndexS;
        unordered_map<char, int> charIndexT;

        for (int i = 0; i < s.length(); i++) {
            if (charIndexS.find(s[i]) == charIndexS.end()) {
                charIndexS[s[i]] = i;
            }

            if (charIndexT.find(t[i]) == charIndexT.end()) {
                charIndexT[t[i]] = i;
            }

            if (charIndexS[s[i]] != charIndexT[t[i]]) {
                return false;
            }
        }

        return true;        
    }
    bool isIsomorphic(string s, string t) {
      unordered_map<char, int> s_to_t, t_to_s;
      for(int i=0;i<s.length();i++)
      {

        if(!s_to_t.count(s[i]))
        {
            s_to_t[s[i]]=i;
        }
        if(!t_to_s.count(t[i]))
        {
            t_to_s[t[i]]=i;
        }
        if(!(s_to_t[s[i]]==t_to_s[t[i]]))
        {
            return false;
        }
      }
      return true;
    }
};

int main()
{
    string s,t;
    cin>>s>>t;
    Solution sol;
    bool ans=sol.isIsomorphic(s,t);
    if(ans)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
}