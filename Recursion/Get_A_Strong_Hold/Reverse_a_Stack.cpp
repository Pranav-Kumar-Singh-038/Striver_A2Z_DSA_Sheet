#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void insertVal(int val, stack<int> &St)
    {
       if(St.empty()){
        St.push(val);
        return;
       }

       int top=St.top();
       St.pop();
       insertVal(val,St);
       St.push(top);
    }

    void Reverse(stack<int> &St) { // until stack is empty, pick the first element store it, reverse the rest of the stack, this will continue picking until every element is popped and stored, then start insert the last, call the insertVal function it will insert if stack is empty which obviously is after popping everything, otherwise if something is present (in the next), first pop the first element then call the insert function again to insert the required val, after which you insert the popped top,
    // TC: O(n^2), SC: O(n^2)
      if(!St.empty())
      {
        int top=St.top();
        St.pop();
        Reverse(St);
        insertVal(top,St);
      }
    }
};

void printStack(stack<int> &St)
{
    if(St.empty())
    {
        return;
    }
    while(!St.empty())
    {
        cout<<St.top()<<" ";
        St.pop();
    }
}

int main()
{
   int n;
   cin>>n;
   stack<int> St;
   for(int i=0;i<n;i++)
   {
     int x;
     cin>>x;
     St.push(x);
   }
   Solution sol;
   sol.Reverse(St);
   printStack(St);
   return 0;
}

