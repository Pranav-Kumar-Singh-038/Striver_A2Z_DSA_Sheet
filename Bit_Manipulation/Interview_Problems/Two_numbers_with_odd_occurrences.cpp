#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N) // if you xor_all we get a^b, to get it separately we will find the rightmost diff bit of a and b, then separate the group into two different buckets based on wether they have the bit set or not, now xor both group, since a and b are now in different groups they will be the only ones left.
    {
        // TC: O(3n), SC: O(n)
        long long int xor_all=0;
        for(int i=0;i<N;i++) // TC: O(n)
        {
            xor_all^=Arr[i];
        }

        long long int diff_bit=xor_all & -xor_all;
        vector<long long int> groupA; // SC: O(n/2)
        vector<long long int> groupB;// SC: O(n/2)
        for(int i=0;i<N;i++) // TC: O(n)
        {
            long long int num=Arr[i];
            if(num & diff_bit)
            {
                groupA.push_back(num);
            }
            else
            {
                groupB.push_back(num);
            }
        }
        long long int a=0,b=0;
        for(auto &it:groupA) // TC: O(n/2)
        {
            a^=it;
        }
        for(auto &it:groupB) // TC: O(n/2)
        {
            b^=it;
        }
        if(a<b)
        {
            return {b,a};
        }
        return {a,b};
    }
};

int main()
{
    int n;
    cin >> n;
    long long int Arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }
    Solution sol;
    vector<long long int> ans = sol.twoOddNum(Arr, n);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}