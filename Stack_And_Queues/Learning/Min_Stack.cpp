#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    int minVal = INT_MAX;

    Node(int val, int min)
    {
        this->val = val;
        this->next = NULL;
        this->minVal = min;
    }
};

class MinStack
{
public:
// TC of all functions is O(1), SC: O(n) (stack size)
    Node *topNode;
    MinStack()
    {
        topNode = NULL;
    }

    void push(int val)
    {
        int minVal = (topNode == NULL) ? val : min(val, topNode->minVal);
        Node *newNode = new Node(val, minVal);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop()
    {
        if (topNode == NULL)
        {
            return;
        }
        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top()
    {
        if(topNode==NULL)
        {
            return 0;
        }
        return topNode->val;
    }

    int getMin()
    {
        if(topNode==NULL)
        {
            return INT_MIN;
        }
        return topNode->minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    int n;
    cin >> n;

    vector<pair<string, int>> vec(n);
    for (auto &pair : vec)
    {
        string first;
        cin >> first;
        int second = 0;
        if (first == "push")
        {
            cin >> second;
        }
        pair = {first, second};
    }

    MinStack stk;

    for (auto &pair : vec)
    {
        string first = pair.first;
        int second = pair.second;

        if (first == "MinStack")
        {
            continue;
        }
        if (first == "push")
        {
            stk.push(second);
        }
        else if (first == "pop")
        {
            stk.pop();
        }
        else if (first == "top")
        {
            int ans = stk.top();
            cout << ans << " ";
        }
        else if (first == "getMin")
        {
            cout << stk.getMin() << " ";
        }
    }

    return 0;
}