#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();

private:
    void insertInSortedOrder(int val)
    {
        // Base case: either stack is empty or top is less than or equal to val
        if (s.empty() || s.top() <= val)
        {
            s.push(val);
            return;
        }

        int temp = s.top();
        s.pop();
        insertInSortedOrder(val); // Recurse till we find right position
        s.push(temp);             // Push the popped element back
    }
};
void SortedStack ::sort() //First remove an element from the stack, go down the recursive function and continue removing, now we insert the element in it's right place, first find what place does it belong to, if the stack is empty which it obviously will be for the first case, insert it, then the previous sort function will try to resolve, then find the correct position again, now this time remove the last element and try to find the correct position again, we keep doing it until the stack is sorted
// Video link -: https://youtu.be/MOGBRkkOhkY?si=XprbueoGoFjFGTLb
{
    // TC: O(n^2), SC: O(n)
    if (!s.empty())
    {
        int top = s.top();
        s.pop();
        sort();                
        insertInSortedOrder(top);
    }
}

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &it : vec)
    {
        cin >> it;
    }
    SortedStack sol;

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        sol.s.push(vec[i]);
    }

    sol.sort();
    printStack(sol.s);
}


/*Sort a stack such that the smallest element is on top, using only recursion (no extra data structures).
🔧 Approach:

    Recursively pop all elements from the stack until it's empty.

    Insert each popped element back into the sorted position using a helper function.

🧩 Functions:
sort():

    Base Case: If stack is empty, return.

    Recursive Step:

        Pop top element.

        Sort the remaining stack.

        Insert the popped element into its correct position.

insertInSortedOrder(val):

    Inserts val into a stack that is already sorted.

    Recursively pops elements until the correct position for val is found.

    Rebuilds the stack by pushing back popped elements.

🧠 Key Idea:

The recursion stack acts as an implicit second stack, helping sort the original stack in-place.
⏱️ Complexity:

    Time: O(n²) – each insertion can take up to O(n) time.

    Space: O(n) – due to recursive calls.
    */

