#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     bool isPalindrome(string s) {
// int start=0;
//        int end=s.size()-1;
//        while(start<=end){
//            if(!isalnum(s[start])){start++; continue;}
//            if(!isalnum(s[end])){end--;continue;}
//            if(tolower(s[start])!=tolower(s[end]))return false;
//            else{
//                start++;
//                end--;
//            }
//        }
//        return true;
//     }
// };

class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());                      
        
        string temp="";
        for(int i=0;i<s.size();i++)
        {
           if(isalnum(s[i]))
            {
              temp+=tolower(s[i]);
            }
        }
      
        if(temp.size()==0)
        {
            return true;
        }
        string rev=temp;
        reverse(rev.begin(),rev.end());

        if(temp==rev)
        {
          return true;
        }
        else
        {
            return false;
        }
    }
};

//the time complexity for both the code is O(n), but the space complexity for the second code is O(1) whereas for the first its O(n)

int main()
{
 string str;
 getline(cin,str);

 Solution sol;
 bool rev=sol.isPalindrome(str);
 cout<<endl<<rev;
}
