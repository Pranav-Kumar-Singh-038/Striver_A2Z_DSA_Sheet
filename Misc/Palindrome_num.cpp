#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0 || (x != 0 && x % 10 == 0)) {
//             return false;
//         }

//         int reversed = 0;
//         while (x > reversed) {
//             reversed = reversed * 10 + x % 10;
//             x /= 10;
//         }
//         return (x == reversed) || (x == reversed / 10);
//     }
// };

class Solution {
public:
    bool isPalindrome(int x) {
        int temp=x;
        long int rev=0;
        if(temp<0)
        {
            return false;
        }
        while(temp!=0)
        {
            rev=rev*10+temp%10;
            temp=temp/10;
        }
        if(rev>INT_MAX || rev<INT_MIN)
            {
                return 0;
            }
       return(rev==x);
    }
};

int main()
{
 int x;
 cin>>x;
 
 Solution sol;
 int rev=sol.isPalindrome(x);
 cout<<endl<<rev;
}
