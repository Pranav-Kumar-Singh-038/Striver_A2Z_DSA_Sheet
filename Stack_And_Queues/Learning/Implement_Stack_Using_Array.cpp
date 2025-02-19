#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack()
    {
        top = -1;
    }
    int pop();
    void push(int);
};

void MyStack ::push(int x) // if top == limit, it is overflow, otherwise top++ and assign a value at that index.
{
    // TC: O(1), SC: O(1)
    if (top == 999)
    {
        cout << "Stack Overflow\n";
        return;
    }
    top++;      
    arr[top] = x; 
}

int MyStack ::pop() // if top==-1, underflow condition, else ans=arr[top] and top--
{
    // TC: O(1), SC: O(1)
    if (top == -1)
    {
        return -1;
    }
    int ans = arr[top]; 
    top--;              
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    for (int &x : input)
    {
        cin >> x;
    }

    MyStack stack;
    for(int i=0;i<n;i++)
    {
        if(input[i]==1)
        {
          stack.push(input[i+1]);
          i+=1;
        }
        else if(input[i]==2)
        {
            cout<<stack.pop()<<" ";
        }
    }

    return 0;
}
