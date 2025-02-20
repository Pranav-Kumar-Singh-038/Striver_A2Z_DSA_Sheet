#include <bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue
{
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue()
    {
        front = rear = NULL;
    }
};
 
// basic idea: rear moves forward as new elements are added, front moves forward as elements are popped
// Edge cases: if rear ==null (at start) while pushing. if front == NULL while popping , if front ==NULL after popping
void MyQueue::push(int x)
{
    // TC: O(1), SC: O(1)
    QueueNode *newNode = new QueueNode(x);
    if (rear == NULL)
    {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = rear->next;
}

int MyQueue ::pop()
{
    // TC: O(1), SC: O(1)
    if (front == NULL)
    {
        return -1;
    }
    int ans = front->data;
    QueueNode *temp = front;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    delete temp;
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

    MyQueue q;
    for (int i = 0; i < n; i++)
    {
        if (input[i] == 1)
        {
            q.push(input[i + 1]);
            i += 1;
        }
        else if (input[i] == 2)
        {
            int ans = q.pop();
            cout << ans << " ";
        }
    }
}
