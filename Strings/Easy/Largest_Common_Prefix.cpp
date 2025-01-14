#include <bits/stdc++.h>
using namespace std;



class Solution {
public:

    string longestCommonPrefixOptimal(vector<string>& strs) {
        // TC : nlogn SC: 1
        if (strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string first = strs[0], last = strs.back(), result = "";
        for (int i = 0; i < first.size(); i++) {
            if (i < last.size() && first[i] == last[i]) {
                result += first[i];
            } else {
                break;
            }
        }
        return result;
    }

    string longestCommonPrefix(vector<string>& strs) 
    {
        // TC : O(n*k) where k is the length of the shortest string SC: O(m) m is the length of smallest string
    if (strs.empty()) return ""; 
     string smallest = strs[0];
     for(auto str:strs)
     {
        if(str.length()<smallest.length())
        {
            smallest=str;
        }
     }
     int smallSize = smallest.length();
     while(smallSize>0)
     {
        bool flag=true;
        for(auto str: strs)
        {
            if(smallest!=str.substr(0, smallSize))
            {
                smallest.pop_back();
                smallSize--;
                flag=false;
                break;
            }
        }
        if(flag)
        {
            return smallest;
        }

     }
         return "";

    }
};


int main()
{
    vector<string> strs;
    int n;
    cin>>n;
    strs.resize(n); 
    for(int i=0;i<n;i++)
    {
        cin>> strs[i];
    }
    Solution sol;
    string ans= sol.longestCommonPrefix(strs);
    cout<<ans;
}