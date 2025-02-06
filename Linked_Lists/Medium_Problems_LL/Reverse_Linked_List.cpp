#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    ListNode *next;
    int data;

    ListNode()
    {
        data = 0;
        next = NULL;
    }

    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ListNode(int data, ListNode *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head) // Iterative
    // TC: O(n) SC: O(1)
    {
        if (head == NULL)
        {
            return head;
        }
        ListNode *current = head;
        ListNode *prev = NULL;
        while (current->next != NULL)
        {
            ListNode *nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        current->next = prev;
        return current;
    }

    ListNode *reverseList2(ListNode *head,  ListNode *prev = NULL) // Recursive
    // TC: O(n) SC: O(n) (recursive call stack)
    {
        if (head == NULL)
        {
           return prev;
        }

        ListNode *nextNode = head->next; 
        head->next = prev;
        ListNode* ans=reverseList2( nextNode, head);
        return ans;
    }

    void printLL(ListNode *head)
    {
        if (head == NULL)
        {
            return;
        }
        ListNode *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }

    ListNode *constructLL(vector<int> vec)
    {
        if (vec.empty())
        {
            return NULL;
        }
        ListNode *head = new ListNode(vec[0]);
        ListNode *current = head;

        for (int i = 1; i < vec.size(); i++)
        {
            ListNode *newNode = new ListNode(vec[i]);
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
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    Solution sol;
    ListNode *head = sol.constructLL(vec);
    ListNode *newHead = sol.reverseList2(head);
    sol.printLL(newHead);
}