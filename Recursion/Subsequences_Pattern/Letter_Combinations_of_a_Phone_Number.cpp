#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void storeCombinations(string digits,unordered_map<char, string>& stringMap, int size, vector<string> &ans, int index, string combination) // the twist for this questions is that, we need to take care of the order of the digits, in 23 since 2 comes first we cannot have d,e,f before a,b,c, also we cannot have ab, bc withing themselves as the first charecter must come from the first digit and so on
    {
        // after that since we need to make all charecter we take all string of 2: a,b,c using a forloop, and we call it via recursion and increase the index, so now within each of a,b,c it will call d,e,f. pop after each to have the exclude case since the forloop visits a,b,c one by one
        // TC: O(4^n), n=str.size(), SC: O(n+n+4^n*n), 4^n is the max possible combinations each of length n
        if (combination.size() == size)
        {
            ans.push_back(combination);
            return;
        }
        if ( index > size)
        {
            return;
        }
        for (char c : stringMap[digits[index]]) // TC: max=4
        {
            combination.push_back(c);// SC: O(n)
            storeCombinations(digits,stringMap,size,ans,index+1,combination); // stack size: O(n)
            combination.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> stringMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        string combination = "";
        vector<string> ans;
        if(digits.empty())
        {
            return ans;
        }
        int index = 0;
        int size = digits.size();
        storeCombinations(digits,stringMap, size, ans, index, combination);
        return ans;
    }
};

int main()
{
    string str;
    cin >> str;

    Solution sol;
    vector<string> ans = sol.letterCombinations(str);
    for (string &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}