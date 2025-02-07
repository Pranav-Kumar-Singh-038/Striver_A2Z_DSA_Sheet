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
    bool hasCycle2(Node *head) // using Unordered map
    {
        // TC: O(n), SC: O(n)
        Node *current = head;
        unordered_map<Node *, bool> myMap;
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

    bool hasCycle(Node *head) // using tortoise and hare (floyd's algorithm)
    {
        // TC: O(n), SC: O(1)
        Node *tortoise = head;
        Node *hare = head;
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

    Node *constructLL(vector<int> vec, int pos)
    {
        if (vec.empty())
        {
            return NULL;
        }

        Node *head = new Node(vec[0]);
        Node *current = head;
        for (int i = 1; i < vec.size(); i++)
        {
            Node *newNode = new Node(vec[i]);
            current->next = newNode;
            current = current->next;
        }

        Node *newHead = addLoop(head, pos);

        return newHead;
    }

    Node *addLoop(Node *head, int pos)
    {
        if (head == NULL || pos == -1)
        {
            return NULL;
        }
        Node *current = head;
        while (current != NULL && pos > 0)
        {
            current = current->next;
            pos--;
        }

        Node *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = current;
        return head;
    }

    void printLL(Node *head)
    {
        if (head == NULL)
        {
            return;
        }
        Node *current = head;
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
    Node *head = sol.constructLL(vec, pos);
    // sol.printLL(head);
    bool ans = sol.hasCycle(head);
    cout << ans;
}
