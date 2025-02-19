#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
    stack<int> input, output;
public:

    void push(int x)
    {
        input.push(x);
    }

    int pop(void)
    {
        int ans = peek();
        output.pop();
        return ans;
    }

    int peek(void)
    {
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }

    bool empty(void)
    {
        return input.empty() && output.empty();
    }
};

// while pushing we remove everything then add x then place everything back. It's like picking a stack of cards, adding a card, then keeping the cards back. this makes a queue with a stack.
// // all operations are O(1) except push which is O(2n), space taken is also O(2n) instead of O(n)
class MyQueue1
{
public:
    stack<int> stk;
    stack<int> stk2;

    void push(int x)
    {
        while (!stk.empty())
        {
            stk2.push(stk.top());
            stk.pop();
        }
        stk.push(x);
        while (!stk2.empty())
        {
            stk.push(stk2.top());
            stk2.pop();
        }
    }

    int pop()
    {
        if (stk.empty())
            return -1;
        int ans = stk.top();
        stk.pop();
        return ans;
    }

    int peek()
    {
        if (stk.empty())
            return -1;
        return stk.top();
    }

    bool empty()
    {
        return stk.empty();
    }
};

int main()
{
    vector<string> input = {"MyQueue", "push", "push", "peek", "pop", "empty"};
    vector<int> inputNum = {1, 2};

    MyQueue *obj = nullptr;
    int j = 0;

    for (const string &cmd : input)
    {
        if (cmd == "MyQueue")
        {
            obj = new MyQueue();
        }
        else if (cmd == "push")
        {
            obj->push(inputNum[j]);
            j++;
        }
        else if (cmd == "peek")
        {
            cout << obj->peek() << " ";
        }
        else if (cmd == "pop")
        {
            cout << obj->pop() << " ";
        }
        else if (cmd == "empty")
        {
            cout << obj->empty() << " ";
        }
    }

    return 0;
}
