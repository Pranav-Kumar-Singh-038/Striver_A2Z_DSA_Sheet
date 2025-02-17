#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void factorial(long long n, long long fact, long long i, vector<long long> &ans)
    {
      if(fact>n)
      {
        return;
      }
      ans.push_back(fact);
      factorial(n,fact*i,i+1,ans); 
    }

    vector<long long> factorialNumbers(long long n) // recursive solution for the same
    {
      // TC: O(logn/log(logn)), SC: O(logn/log(logn)) recursive stack and the recursive stack depth is O(i)
      long long i=2;
      long long fact=1;
      vector<long long> ans;
      factorial(n,fact,i,ans); 
      return ans;
    }

    vector<long long> factorialNumbers0(long long n) // take fact=1, i=2, continue until fact less or equal to n and push fact into ans vector
    {
        // TC: O(logn/log(logn)), SC: O(1) not considering ans vector

        // TC is O(i), i is the largest integer such that i!≤n. for example i for 25 is 4 since 5 gives 120.
        // Use stirling's approximation to the factorial equation, for i!~n, take ln both side the you get i*ln(i)=ln(n), then solve this using lambert's equation for i.
        vector<long long> ans;
        long long fact = 1;
        long long i = 2;
        while (fact <= n)
        {
            ans.push_back(fact);
            fact *= i;
            i++;
        }
        return ans;
    }
};

int main()
{
    long long n;
    cin >> n;
    Solution sol;
    vector<long long> ans = sol.factorialNumbers(n);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}