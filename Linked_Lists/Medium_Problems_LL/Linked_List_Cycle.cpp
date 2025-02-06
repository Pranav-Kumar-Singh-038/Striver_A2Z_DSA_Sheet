#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

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
};

class Solution
{
public:
    bool hasCycle2(ListNode *head) // using Unordered map
    {
        // TC: O(n), SC: O(n)
        ListNode *current = head;
        unordered_map<ListNode *, bool> myMap;
        while (current != NULL && myMap[current] != true)
        {
            myMap[current] = true;
            current = current->next;
        }
        if (current == NULL)
        {
            return false;
        }
        return true;
    }

    bool hasCycle(ListNode *head) // using tortoise and hare (floyd's algorithm)
    {
        // TC: O(n), SC: O(1)
        ListNode *tortoise = head;
        ListNode *hare = head;
        if(head==NULL || head->next==NULL)
        {
            return false;
        }

        while (hare && hare->next)
        {
            tortoise = tortoise->next;
            hare=hare->next->next;
            if(tortoise==hare)
            {
                return true;
            }
        }
        return false;
    }

    ListNode *constructLL(vector<int> vec, int pos)
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

        ListNode *newHead = addLoop(head, pos);

        return newHead;
    }

    ListNode *addLoop(ListNode *head, int pos)
    {
        if (head == NULL || pos == -1)
        {
            return NULL;
        }
        ListNode *current = head;
        while (current != NULL && pos > 0)
        {
            current = current->next;
            pos--;
        }

        ListNode *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = current;
        return head;
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
};

int main()
{
    int n, pos;
    cin >> n;
    cin >> pos;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    Solution sol;
    ListNode *head = sol.constructLL(vec, pos);
    // sol.printLL(head);
    bool ans = sol.hasCycle(head);
    cout << ans;
}
