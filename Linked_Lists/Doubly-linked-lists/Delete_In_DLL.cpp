#include <bits/stdc++.h>
using namespace std;

class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    DLLNode(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution
{
public:
    DLLNode *deleteNode(DLLNode *head, int x)
    {
        if (!head)
            return NULL;

        DLLNode *current = head;
        if (x == 1)
        {
            head = current->next;
            if (head)
            {
                head->prev = NULL;
            }
            delete current;
            return head;
        }

        for (int i = 1; i < x - 1 && current; i++)
        {
            current = current->next;
        }

        if (!current || !current->next)
        {
            return head;
        }

        DLLNode *delNode = current->next;
        current->next = delNode->next;

        if (delNode->next)
        {
            delNode->next->prev = current;
        }
        delete delNode;
        return head;
    }

    DLLNode *constructDLL(vector<int> vec)
    {
        if (vec.empty())
        {
            return NULL;
        }
        DLLNode *head = new DLLNode(vec[0]);
        DLLNode *current = head;
        for (int i = 1; i < vec.size(); i++)
        {
            DLLNode *newNode = new DLLNode(vec[i]);
            current->next = newNode;
            newNode->prev = current;
            current = current->next;
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
    int x;
    cin >> x;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    Solution sol;
    DLLNode *head = sol.constructDLL(vec);
    DLLNode *newHead = sol.deleteNode(head, x);
    sol.printDLL(newHead);
    return 0;
}