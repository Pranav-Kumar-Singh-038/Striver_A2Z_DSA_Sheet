#include <bits/stdc++.h>
using namespace std;

/*The code you provided is using an istringstream object to extract words from a string s. Here's how it works:

    istringstream iss(s): This line creates an input string stream (istringstream) object named iss and initializes it with the string s.
     An input string stream is similar to cin, but it reads from a string instead of the standard input.

    string word; This declares a string variable named word which will be used to store each word extracted from the string.

    while(iss >> word): This is a while loop that reads words from the istringstream object iss. The expression iss >> word attempts to extract a
    word from the stream. If extraction is successful, the loop continues; if it fails (e.g., because there are no more words to extract), the loop terminates.

    words.push_back(word): Inside the loop, each successfully extracted word is added to a vector (assuming words is a std::vector<string>). The push_back
    function is used to add the word to the end of the vector.*/

// Optima
//  TC: same, SC: same
class Solution
{
private:
    void reverse(string &s, int i, int j)
    {
        while (i < j)
        {
            char temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
    }

public:
    string reverseWords(string &s)
    {
        int i = 0, j = 0;
        int l = 0;
        int len = s.length();
        int wordcount = 0;
        while (true)
        {
            while (i < len && s[i] == ' ')
            {
                i++;
            }
            if (i == len)
            {
                break;
            }
            if (wordcount)
            {
                s[j++] = ' ';
            }
            l = j;
            while (i < len && s[i] != ' ')
            {
                s[j] = s[i];
                j++;
                i++;
            }
            reverse(s, l, j - 1);
            wordcount++;
        }
        s.resize(j);
        reverse(s, 0, j - 1);
        return s;
    }
};

// TC: O(n), n is the length of string
//  SC: O(1)
// class Solution
// {
// public:
//     string reverseWords(string s)
//     {
//         vector<string> words;
//         string ans = "";
//         istringstream iss(s);

//         string word;
//         while (iss >> word)
//         {
//             ans = word + " " + ans;
//         }
//         if (!ans.empty())
//         {
//             ans.pop_back();
//         }
//         return ans;
//     }
// };

int main()
{
    string str;
    getline(cin, str);
    Solution sol;
    string ans = sol.reverseWords(str);
    cout << ans;
}