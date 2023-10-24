// class Solution {                      
// public:
//     int reverse(int x) {
//         int r=0;      // decleare r 
//         while(x){
//          if (r>INT_MAX/10 || r<INT_MIN/10) return 0; // check 32 bit range if r is outside the range then return 0 
//          r=r*10+x%10; // find remainder and add its to r
//          x=x/10;     // Update the value of x
//         } 
//         return r;  // if r in the 32 bit range then return r
//     }
// }; 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int temp=x;
        long int rev=0;
        while(temp!=0)
        {
         rev=rev*10+(temp%10);
         temp=temp/10;
        }
        if(rev>2147483647 || rev<-2147483648)
        {
            return 0;
        }
        return rev;
    }
};

int main()
{
 int x;
 cin>>x;
 
 Solution sol;
 int rev=sol.reverse(x);
 cout<<endl<<rev;
}