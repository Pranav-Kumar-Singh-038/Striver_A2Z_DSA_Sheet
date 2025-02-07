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
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Solution
{
public:
    Node *segregate(Node *head)  // Make 3 separate lists, then combine them
    {
        // TC: O(n), SC: O(1)
        Node *zeroD = new Node(-1);
        Node *oneD = new Node(-1);
        Node *twoD = new Node(-1);
        Node *zeroes = zeroD;
        Node *ones = oneD;
        Node *twos = twoD;
        Node *current = head;
        while (current != NULL)
        {
            if (current->data == 0)
            {
                zeroes->next = current;
                zeroes = zeroes->next;
            }
            else if (current->data == 1)
            {
                ones->next = current;
                ones = ones->next;
            }
            else
            {
                twos->next = current;
                twos = twos->next;
            }
            current = current->next;
        }

        if (oneD->next != NULL)
        {
            zeroes->next = oneD->next;
        }
        else
        {
            zeroes->next = twoD->next;
        }
        ones->next = twoD->next;
        twos->next = NULL;

        head = zeroD->next;
        delete zeroD;
        delete oneD;
        delete twoD;
        return head;
    }
    
    Node *segregate2(Node *head) // Counting the number of occurrences of each and then modifying the original list
    {
        // TC: O(n), SC: O(1)
        Node *current = head;
        int Zeroes = 0, Ones = 0, Twos = 0;
        while (current != NULL)
        {
            if (current->data == 0)
            {
                Zeroes++;
            }
            else if (current->data == 1)
            {
                Ones++;
            }
            else
            {
                Twos++;
            }
            current = current->next;
        }

        Node *newCurrent = head;
        while (newCurrent != NULL)
        {
            if (Zeroes > 0)
            {
                newCurrent->data = 0;
                Zeroes--;
            }
            else if (Ones > 0)
            {
                newCurrent->data = 1;
                Ones--;
            }
            else
            {
                newCurrent->data = 2;
            }
            newCurrent = newCurrent->next;
        }

        return head;
    }

    Node *constructLL(vector<int> vec)
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
        return;
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
    Node *head = sol.constructLL(vec);
    Node *newHead = sol.segregate(head);
    sol.printLL(newHead);
    return 0;
}