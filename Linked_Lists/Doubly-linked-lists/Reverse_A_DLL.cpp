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
    DLLNode *reverseDLL(DLLNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        DLLNode *current = head;
        DLLNode *newHead = NULL;
        while (current != NULL)
        {
            DLLNode *temp = current->next;
            current->next = current->prev;
            current->prev = temp;

            newHead = current; 
            current = temp;
        }
        return newHead;
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
        if (head == NULL)
        {
            return;
        }

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
    DLLNode *newHead = sol.reverseDLL(head);
    sol.printDLL(newHead);
}