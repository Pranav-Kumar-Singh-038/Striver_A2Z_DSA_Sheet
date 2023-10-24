#include <bits/stdc++.h>
using namespace std;

// class Solution {
//     int dp[33];
// public:
//     int fibon(int n) {
//         cout<<n<<endl;
//         if(n==1)return 1;
//         if(n<=0)return 0;

//         int& ans = dp[n];
//         if(ans!=-1)return ans;

//         return ans = fibon(n-1) + fibon(n-2);
//     }

//     int fib(int n){
//         for(int i = 0 ; i < 33 ; i++)dp[i]=-1;
//         int ans = fibon(n);
//         return ans;
//     }
// };

//  class Solution {
// public:
//     int fib(int n) {
//         if (n == 0 || n == 1)
//             return n;
//         int prev2 = 0, prev = 1;
//         int f = 0;
//         for (int i = 2; i <= n; i++) {
//             f = prev + prev2;
//             prev2 = prev;
//             prev = f;
//         }
//         return f;
//     }
// };

// the top method is  Fibonacci sequence using memoization (top-down dynamic programming)  ||time and space complexity =O(n), O(1)
// the second method is same as my approach but instead of using array it stores the prev 2 values in temporary variables ||time and space complexity =O(n), O(1)
// the third is my approach using arrays to store all values || time and space complexity =O(n), O(n)

class Solution {
public:
    int fib(int n) {
        if(n==0)
        {
            return 0;
        }
        int arr[n+1];
        arr[0]=0;
        arr[1]=1;
        for(int i=2;i<=n;i++)
        {
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n];
    }
};

int main()
{
    int x;
    cin>>x;

    Solution sol;
    int ans=sol.fib(x);
    cout<<ans;
}
