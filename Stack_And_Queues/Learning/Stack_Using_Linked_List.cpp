#include <bits/stdc++.h>
using namespace std;

class StackNode
{
public:
    int val;
    StackNode *next;

    StackNode()
    {
        this->val = 0;
        this->next = NULL;
    }

    StackNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }

    StackNode(int val, StackNode *next)
    {
        this->val = val;
        this->next = next;
    }
};

class MyStack // the problem comes when popping because if you keep the top at the last node, you won't have any means to go back
{ // to resolve this, make the linked list backwards, take a value make a node connect the node's next to current top, then move top to new node, 
private:// doing this you will be able to move down the stack when moving forward in the ll
    StackNode *top;

public: // TC: O(1), SC: O(n)
    void push(int x)
    {
        StackNode *newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (top == NULL)
        {
            return -1;
        }
        int ans = top->val;
        StackNode *temp = top;
        top = top->next;
        delete temp;
        return ans;
    }

    MyStack()
    {
        top = NULL;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    for (int &x : input)
    {
        cin >> x;
    }

    MyStack stk;
    for (int i = 0; i < n; i++)
    {
        if (input[i] == 1)
        {
            stk.push(input[i + 1]);
            i += 1;
        }
        else if (input[i] == 2)
        {
            int ans = stk.pop();
            cout << ans << " ";
        }
    }
}
