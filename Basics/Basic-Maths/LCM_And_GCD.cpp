#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> lcmAndGcd(int a, int b) // Use euclidean algorithm to find gcd then => LCM X GCD = a X b
    { // always store numb, then keep the remainder in numb, then numb in numa, this ensure the smaller num is always numb and numa is gcd
        // worst case is for consecutive fibonacci numbers
        // TC: O(log min(a, b))  where log base 2 is taken, SC: O(1)
        int numA = a, numB = b;
        while (numB != 0) {
            int temp = numB;
            numB = numA % numB;
            numA = temp;
        }  
        int GCD = numA;
        int LCM = (a / GCD) * b;  // divide first to avoid overflow
        
        return {LCM, GCD};
    }

};

int main()
{
    int a,b;
    cin>>a>>b;
    Solution sol;
    vector<int> ans=sol.lcmAndGcd(a,b);
    cout<<ans[0]<<" "<<ans[1];
}