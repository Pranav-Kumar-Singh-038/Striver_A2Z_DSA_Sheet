#include <bits/stdc++.h>
using namespace std;

class StockSpanner {// TC: O(1) amortized, SC:O (n)
    stack<pair<int,int>> stk;  // SC: O(n) in worst case
public:
    StockSpanner() {}
    
    int next(int price) {
        int count = 1;
        while(!stk.empty() && stk.top().first<=price) // TC: amortized O(1) per call, worst-case O(n) for 1 call
        {
            count+=stk.top().second;
            stk.pop();
        }
        stk.push({price,count});
        return count;
    }
};

// Explanation for time complexity-:
// Worst-case per call: O(n), when all previous prices are popped

// But: each price is popped only once over all calls

// → So total time for n calls is O(n)

// → Amortized time per call is O(1)


class StockSpanner1 // TC:O (n), SC:O(n), here TC: for n calls is O(n^2)
{
    vector<int> vec; // SC: O(n)

public:
    StockSpanner1()
    {
    }

    int next(int price)
    {
        int count = 1;
        int i = vec.size() - 1;
        while (i >= 0 && vec[i] <= price) // TC:O (n)
        {
            count++;
            i--;
        }
        vec.push_back(price);
        return count;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &it : vec)
    {
        cin >> it;
    }

    StockSpanner sol;
    for (int &it : vec)
    {
        cout << sol.next(it) << " ";
    }
    return 0;
}