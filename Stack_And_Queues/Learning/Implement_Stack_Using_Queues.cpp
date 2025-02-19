#include <bits/stdc++.h>
using namespace std;

class MyStack // only top and pop have changed functionalities, everything else is same.
// for pop, since que will remove from front, keep pushing first to back then popping it, untill one element is left,  then store it and pop.
// for top, return que.back()
// TC: O(n) for pop rest are O(1), SC: O(1) except the storage required
{
public:
    queue<int> que;

    void push(int x)
    {
        que.push(x);
    }

    int pop()
    {
       int size=que.size();
       while(size>1)
       {
        que.push(que.front());
        que.pop();
        size--;
       }
       int ans=que.front();
       que.pop();
       return ans;
    }

    int top()
    {
        return que.back();
    }

    bool empty()
    {
        return que.empty();
    }
};

int main()
{
    vector<string> input = {"MyStack", "push", "push", "top", "pop", "empty"};
    vector<int> inputNum = {1, 2};

    MyStack *obj = new MyStack();
    int j = 0;
    for (const string &cmd : input)
    {
        if (cmd == "push")
        {
            obj->push(inputNum[j]);
            j++;
        }
        else if (cmd == "top")
        {
            int ans=obj->top();
            cout << ans << " ";
        }
        else if (cmd == "pop")
        {
            int ans=obj->pop() ;
            cout << ans << " ";
        }
        else if (cmd == "empty")
        {
            int ans=obj->empty();
            cout << ans << " ";
        }
    }

}
