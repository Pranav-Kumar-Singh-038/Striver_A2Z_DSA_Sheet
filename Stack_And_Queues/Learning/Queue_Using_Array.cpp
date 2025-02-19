#include <bits/stdc++.h>
using namespace std;

class MyQueue {
  private:
    int arr[100005];
    int front;
    int rear;

  public:
    MyQueue() {
        front = 0;
        rear = 0;
    }

    void push(int);
    int pop();
};

void MyQueue ::push(int x) { // simple enough
    // TC: O(1), SC: O(1)
    if(rear==100004)
    {
        cout<<"Queue overflow";
        return;
    }
    arr[rear]=x;
    rear++;
    return;
}

int MyQueue ::pop() { // instead of shifting each element we simply move front forward
    // TC: O(1), SC: O(1)
    if (rear == front) {
        return -1; // Queue Underflow
    }
    int ans = arr[front]; 
    front++;  
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

    MyQueue queue;
    for(int i=0;i<n;i++)
    {
        if(input[i]==1)
        {
          queue.push(input[i+1]);
          i+=1;
        }
        else if(input[i]==2)
        {
            cout<<queue.pop()<<" ";
        }
    }

    return 0;
}

