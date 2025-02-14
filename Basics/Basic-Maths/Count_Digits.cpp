#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evenlyDivides(int n)
    {
        // TC: O(logn), SC: O(1)
        int num=n;
        int count=0;
        int digit;
        while(num!=0)
        {
            digit=num%10;
            if(digit!=0 && n%digit==0)
            {
              count++;
            }
            num/=10;
        }
        return count;
    }

};

int main()
{
    int n;
    cin>>n;
    Solution sol;
    int ans=sol.evenlyDivides(n);
    cout<<ans;
    return 0;
}