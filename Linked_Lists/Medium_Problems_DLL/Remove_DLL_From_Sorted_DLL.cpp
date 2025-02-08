#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution
{
public:
    Node *removeDuplicates(Node *head) // Skipping duplicate nodes
    {
        // TC: O(n), SC: O(1)
        if (!head || !head->next)
        {
            return head;
        }

        Node *current = head;

        while (current->next != NULL)
        {
            if (current->data == current->next->data)
            {
                Node *temp = current->next;
                current->next = current->next->next; 

                if (current->next)
                {                                 
                    current->next->prev = current; 
                }

                delete temp; 
            }
            else
            {
                current = current->next; 
            }
        }

        return head;
    }
    
    Node *constructDLL(vector<int> vec)
    {
        Node *head = new Node(vec[0]);
        Node *current = head;
        for (int i = 1; i < vec.size(); i++)
        {
            Node *newNode = new Node(vec[i]);
            current->next = newNode;
            newNode->prev = current;
            current = current->next;
        }
        return head;
    }

    void printDLL(Node *head)
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
        return;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);

    for (int &x : vec)
    {
        cin >> x;
    }

    Solution sol;
    Node *head = sol.constructDLL(vec);
    Node *newHead = sol.removeDuplicates(head);
    sol.printDLL(newHead);
}