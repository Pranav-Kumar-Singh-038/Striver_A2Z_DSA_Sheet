#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findNthFibonacci(int n) {
    vector < int > arr(n);
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n - 1];

          }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
int n;
        cin >> n;
        Solution ob;
        cout << ob.findNthFibonacci(n);
        cout << "\n";
    }
    return 0;
}

