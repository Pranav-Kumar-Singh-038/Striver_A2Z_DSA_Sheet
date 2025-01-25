#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Solution
{
public:
    Node *constructLL(vector<int> &arr)
    {
        if (arr.empty())
        {
            return NULL;
        }
        Node *head = new Node(arr[0]);
        Node *current = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *newNode = new Node(arr[i]);
            current->next = newNode;
            current = current->next;
        }

        return head;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    Solution sol;
    Node *ans = sol.constructLL(arr);
    cout << ans << endl;
}

// } Driver Code Ends