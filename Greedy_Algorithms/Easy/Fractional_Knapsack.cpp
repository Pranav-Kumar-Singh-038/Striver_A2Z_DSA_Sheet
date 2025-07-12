#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int val, wt;
    double perVal;
    Item() {}

    Item(int val, int wt)
    {
        this->val = val;
        this->wt = wt;
        this->perVal = (wt != 0) ? (double)val / wt : 0;
    }

    bool operator<(const Item &other) const // new thingy
    {
        return perVal < other.perVal;
    }
};

bool compare(const Item &a, const Item &b) // new thingy
{
    return a.perVal > b.perVal;  // descending order
}

class Solution
{
public:
    double fractionalKnapsack1(vector<int> &val, vector<int> &wt, int capacity)
    {
        // more optimal, we just make the item list, sort it using a custom comparator function
        // then iterate the items, and keep pushing until capacity is there, the comparator in sort is simpler too
        // it needs two const items a and b, and return a>b, because if it is true it won't do anything and for false, 
        // it will swap them
        // TC:O(2n+nlogn), SC:O(n)
        int n = val.size();
        vector<Item> items; // SC:O(n)

        for (int i = 0; i < n; ++i) // TC:O(n)
        {
            items.emplace_back(val[i], wt[i]);
        }

        sort(items.begin(), items.end(), compare); // TC:O(nlogn)

        double totalValue = 0.0;
        int spaceLeft = capacity;

        for (Item &item : items) // TC:O(n)
        {
            if (spaceLeft >= item.wt)
            {
                totalValue += item.val;
                spaceLeft -= item.wt;
            }
            else
            {
                totalValue += item.perVal * spaceLeft;
                break;
            }
        }

        return totalValue;
    }

    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // Sub optimal
        // The idea is simple, we will have a max heap of items, we go on popping the heap,
        // if the item wt, is less than the space left, we add it all else we add whatever space
        // is left and break;
        // New= the only new point is to make a maxHeap of objects, we need to tell the heap
        // how to compare them, which is done by perVal of item, if perVal of item is lesser than
        // perval of other item we swap their position, to make a maxHeap
        // TC:O(2nlogn)=O(nlogn), SC:O(n)
        double value = 0.0;
        int spaceLeft = capacity;
        priority_queue<Item> maxHeap; // SC:O(n)
        int n = val.size();
        for (int i = 0; i < n; i++) // TC:O(n)
        {
            double perVal = (wt[i] != 0) ? (double)val[i] / wt[i] : 0;
            maxHeap.push(Item(val[i], wt[i])); // TC:O(logn)
        }
        while (!maxHeap.empty()) // TC:O(n)
        {
            Item item = maxHeap.top();
            double perValue = item.perVal;
            int wt = item.wt;
            if (wt <= spaceLeft)
            {
                spaceLeft -= wt;
                value += perValue * wt;
                maxHeap.pop(); // TC:O(logn)
            }
            else
            {
                value += perValue * spaceLeft;
                spaceLeft = 0;
                break;
            }
        }
        return value;
    }
};

int main()
{
    int n, capacity;
    cin >> n >> capacity;
    vector<int> val(n), wt(n);
    for (int &it : val)
    {
        cin >> it;
    }
    for (int &it : wt)
    {
        cin >> it;
    }
    Solution sol;
    double ans = sol.fractionalKnapsack(val, wt, capacity);
    cout << ans;
}