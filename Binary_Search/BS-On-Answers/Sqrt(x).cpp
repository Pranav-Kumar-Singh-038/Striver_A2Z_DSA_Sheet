#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int mySqrt(int x) {
            int l = 0, r = x;
            int mid;
            
            while (l <= r) {
                mid = l + (r - l) / 2;
                long long square = (long long)mid * mid;
    
                if (square == x) {
                    return mid; 
                } else if (square < x) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            
            return r;
        }
};
    


int main()
{
    int x;
    cin>>x;
    Solution sol;
    int ans=sol.mySqrt(x);
    cout<<ans;
}