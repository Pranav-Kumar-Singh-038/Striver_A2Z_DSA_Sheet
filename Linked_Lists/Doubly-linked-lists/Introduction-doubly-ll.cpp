#include <bits/stdc++.h>
using namespace std;

class DLLNode
{
public:
    DLLNode *prev;
    int data;
    DLLNode *next;
    DLLNode()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }
    DLLNode(int data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
};

class Solution
{
public:
    DLLNode *constructDLL(vector<int> &vec)
    {
        if (vec.empty())
            return NULL;
        DLLNode *head = new DLLNode(vec[0]);
        DLLNode *current = head;
        DLLNode *previous = NULL;
        for (int i = 1; i < vec.size(); i++)
        {
            DLLNode *newNode = new DLLNode(vec[i]);
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
        return head;
    }

    void printDLL(DLLNode *head)
    {
        DLLNode *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    Solution sol;
    DLLNode *head = sol.constructDLL(vec);
    sol.printDLL(head);
}
