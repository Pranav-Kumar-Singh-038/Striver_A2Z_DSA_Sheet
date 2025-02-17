#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bitManipulation(int num, int i) // without bitset
    {
        // TC: O(1), SC: O(1)
        bool bit=(num>>(i-1)) & 1;
        cout<< bit<<" ";
        int setVal=num | (1<<(i-1));
        cout<< setVal<<" ";
        int resetVal= num & ~(1<<(i-1));
        cout<<resetVal;
    }

    void bitManipulation0(int num, int i) // using bitset
    {
        // TC: O(1), SC: O(1)
        bitset<31> binary(num);
        cout << binary.test(i - 1) << " ";
        binary.set(i - 1);
        cout << binary.to_ulong() << " ";
        binary.reset(i - 1);
        cout << binary.to_ulong();
    }
};

int main()
{
    int num, i;
    cin >> num >> i;
    Solution sol;
    sol.bitManipulation(num, i);
    return 0;
}